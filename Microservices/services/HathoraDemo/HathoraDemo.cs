using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using Beamable.Common;
using Beamable.Server;
using Beamable.Server.Api.RealmConfig;
using Newtonsoft.Json;
using UnityEngine;
using Lobby = Beamable.Experimental.Api.Lobbies.Lobby;

namespace Beamable.HathoraDemo
{
    [Microservice("HathoraDemo")]
    public class HathoraDemo : Microservice, IFederatedGameServer<HathoraIdentity>
    {
        /// <summary>
        /// Implementation of <see cref="IFederatedGameServer{HathoraIdentity}.CreateGameServer"/>.
        /// Beamable calls this endpoint as a match gets made (before clients are notified).
        ///
        /// This will provision a Hathora game server for the given lobby --- wait for it to become ready and then return the connection information to Beamable.
        /// Beamable will copy the returned <see cref="ServerInfo.globalData"/> into the Lobby's global data dictionary. 
        /// </summary>
        public async Promise<ServerInfo> CreateGameServer(Lobby lobby)
        {
            var roomId = lobby.lobbyId;
            BeamableLogger.Log($"Trying to provision game server for lobby={roomId} --- From={Context.UserId}");

            RealmConfig config = await Services.RealmConfig.GetRealmConfigSettings();

            var matchMakingConfig = GetMatchmakingConfig(config);

            // INFO: Imagine you want to prefetch player data and store it in the lobby's global or player data.
            // INFO: Maybe it makes it easier to initialize the game server if the data is already in the lobby or something like this.
            // INFO: In this case, you'll want to kick these tasks here --- before you start provisioning the game server.

            // get the gamer tags of the players in the lobby
            var gamerTags = lobby.players.Select(p => long.Parse(p.playerId)).ToArray();

            // This is here to fix an issue that exists in the beamable backend --- the fix should go out "Soon TM".
            // Until this is fixed, every request made from this federated endpoint to "Services.WhateverService" needs to be made through the assumedFakeLeader.
            var assumedFakeLeader = AssumeNewUser(gamerTags.First());

            // get the ping times for each player
            var tasks = new List<Promise<Dictionary<string, string>>>(gamerTags.Length);
            tasks.AddRange(gamerTags.Select(tag => assumedFakeLeader.Services.Stats.GetStats("client", "public", "player", tag, new string[] { Stats.HathoraPings })));
            var pingStats = await Promise.Sequence(tasks);
            var pings = pingStats.Select(ping => JsonUtility.FromJson<HathoraPingTimes>(ping[Stats.HathoraPings])).ToArray();

            // Find the best region for this match based on the players in it.
            var region = GetBestRegion(pings);

            // provision the game server
            var response = await CreateHathoraGameServer(config, roomId, region);

            // We get this since the GetConnectionInfo returned JSON doesn't have the processId AND you can't have null objects in the returning dictionary.
            // Since we'll be override the "response" until GetConnectionInfo returns that the room is active, we need to set this with the value of the original CreateHathoraGameServer call.
            var processId = response.processId;

            // Start polling until its active or the initialization timed out.
            var pollingInterval = TimeSpan.FromSeconds(matchMakingConfig.PollingInterval);
            var startedAt = DateTime.Now;

            // MaxWaitTime cannot be more than 2 minutes as the current Beamable-enforced timeout is set to 2 minutes.
            var maxWaitTime = TimeSpan.FromSeconds(matchMakingConfig.MaxWaitTime);

            // Spin for up-to-2-minutes and checking every "PollingInterval" for the connection to become active.
            while (response.status != "active" && (DateTime.Now - startedAt).TotalSeconds < (maxWaitTime).TotalSeconds)
            {
                BeamableLogger.Log($"Room {roomId} status: {response.status}");
                await Task.Delay(pollingInterval);
                response = await PollHathoraGameServer(config, roomId);
            }

            // It took to long to provision the server.
            if (response.status != "active")
            {
                BeamableLogger.LogError($"Failed to provision game server in time for room. ROOM_ID={roomId}, LAST_HATHORA_CONN_UPDATE={JsonUtility.ToJson(response)}");
                throw new MicroserviceException(503, "FAILED_TO_PROVISION_GAME_SERVER_BEFORE_TIMEOUT", JsonUtility.ToJson(response));
            }

            // INFO: After provision the server, await the list of "prefetch data" tasks you kicked earlier.
            // This reduces the chance of timeouts significantly as you make the prefetch requests concurrently with the provisioning.
            // await Task.WhenAll(tasks);

            // INFO: The dictionaries here can never have any null values or keys.
            return new ServerInfo
            {
                globalData = new Dictionary<string, string>
                {
                    { "roomId", roomId },
                    { "processId", processId },
                    { "host", response.exposedPort.host },
                    { "name", response.exposedPort.name },
                    { "port", response.exposedPort.port.ToString() },
                    { "transportType", response.exposedPort.transportType },
                },
                playerData = new()
            };
        }

        private static string GetBestRegion(IReadOnlyCollection<HathoraPingTimes> pings)
        {
            if (pings == null || !pings.Any())
                return null;

            var averagePings = pings.Aggregate((a, b) => a + b) / pings.Count;
            var sortedPings = averagePings.GetSortedPingTimes();

            return sortedPings.First().Key;
        }

        /// <summary>
        /// Takes in the roomId (in our case, the LobbyId) and calls the Hathora API based on realm-config settings and awaits for the response.
        /// </summary>
        private static async Task<HathoraConnectionInfo> CreateHathoraGameServer(RealmConfig config, string roomId, string region = null)
        {
            var hathoraRealmConfig = GetHathoraRealmConfig(config);
            var createUri = new Uri(hathoraRealmConfig.HathoraURL, $"/rooms/v2/{hathoraRealmConfig.AppId}/create?roomId={roomId}");

            var body = new HathoraCreateRoomRequest
            {
                roomConfig = "",
                region = region ?? hathoraRealmConfig.FallbackRegion
            };

            var serialized = JsonUtility.ToJson(body);
            var requestContent = new StringContent(serialized, Encoding.UTF8, "application/json");

            var http = new HttpClient() { DefaultRequestHeaders = { { "Authorization", $"Bearer {hathoraRealmConfig.DeveloperToken}" } } };
            var response = await http.PostAsync(createUri, requestContent);
            var content = await response.Content.ReadAsStringAsync();
            BeamableLogger.Log("Create Room Hathora Response: " + content);
            if (!response.IsSuccessStatusCode)
            {
                throw new Exception(content);
            }

            return JsonUtility.FromJson<HathoraConnectionInfo>(content);
        }

        /// <summary>
        /// Takes in the roomId (in our case, the LobbyId) and calls the Hathora API to get their room's connection information/state.
        /// We use this to wait until the server is provisioned before notifying players that the match is ready.
        /// </summary>
        private static async Task<HathoraConnectionInfo> PollHathoraGameServer(RealmConfig config, string roomId)
        {
            var hathoraRealmConfig = GetHathoraRealmConfig(config);
            var getUri = new Uri(hathoraRealmConfig.HathoraURL, $"/rooms/v2/{hathoraRealmConfig.AppId}/connectioninfo/{roomId}");

            var http = new HttpClient() { DefaultRequestHeaders = { { "Authorization", $"Bearer {hathoraRealmConfig.DeveloperToken}" } } };
            var response = await http.GetAsync(getUri);
            var content = await response.Content.ReadAsStringAsync();
            BeamableLogger.Log("Get ConnectionInfo Hathora Response: " + content);
            if (!response.IsSuccessStatusCode)
            {
                throw new Exception(content);
            }

            return JsonUtility.FromJson<HathoraConnectionInfo>(content);
        }

        /// <summary>
        /// Utility function defining defaults and keys for the "hathora_integration" realm-config namespace.
        /// These must be correctly set up in your realm for this microservice to work. 
        /// </summary>
        private static HathoraRealmConfig GetHathoraRealmConfig(RealmConfig config)
        {
            const string kNamespaceHathoraIntegration = "hathora_integration";
            const string kKeyAppID = "app_id";
            const string kKeyDevToken = "dev_token";
            const string kKeyFallbackRegion = "fallback_region";
            const string kKeyHathoraURL = "hathora_url";


            var hathoraRealmConfig = new HathoraRealmConfig();
            hathoraRealmConfig.AppId = config.GetSetting(kNamespaceHathoraIntegration, kKeyAppID);
            hathoraRealmConfig.DeveloperToken = config.GetSetting(kNamespaceHathoraIntegration, kKeyDevToken);
            hathoraRealmConfig.FallbackRegion = config.GetSetting(kNamespaceHathoraIntegration, kKeyFallbackRegion, "Seattle");
            hathoraRealmConfig.HathoraURL = new Uri(config.GetSetting(kNamespaceHathoraIntegration, kKeyHathoraURL, "https://api.hathora.dev"));

            return hathoraRealmConfig;
        }

        private static MatchMakingConfig GetMatchmakingConfig(RealmConfig config)
        {
            const string kNamespaceMatchMaking = "matchmaking";
            const string kKeyPollingInterval = "polling_interval";
            const string kKeyMaxWaitTime = "max_wait_time";

            var matchMakingConfig = new MatchMakingConfig();
            matchMakingConfig.PollingInterval = float.Parse(config.GetSetting(kNamespaceMatchMaking, kKeyPollingInterval, "5"));
            matchMakingConfig.MaxWaitTime = float.Parse(config.GetSetting(kNamespaceMatchMaking, kKeyMaxWaitTime, "120"));

            return matchMakingConfig;
        }
    }

    public class HathoraIdentity : IThirdPartyCloudIdentity
    {
        public string UniqueName => "hathora";
    }

    public static class Stats
    {
        public const string HathoraPings = "hathora_demo.pings";
    }

    [Serializable]
    public class HathoraCreateRoomRequest
    {
        public string roomConfig;
        public string region;
    }

    [Serializable]
    public class HathoraPortInfo
    {
        public string host;
        public string name;
        public int port;
        public string transportType;
    }

    [Serializable]
    public class HathoraConnectionInfo
    {
        public string processId;
        public string roomId;
        public string status;
        public HathoraPortInfo exposedPort;
        public List<HathoraPortInfo> additionalExposedPorts;
    }

    public class HathoraRealmConfig
    {
        public string AppId;
        public string DeveloperToken;
        public string FallbackRegion;
        public Uri HathoraURL;
    }

    public class MatchMakingConfig
    {
        public float PollingInterval;
        public float MaxWaitTime;
    }

    [Serializable]
    public class HathoraPingTimes
    {
        [JsonProperty("Los_Angeles")] public int LosAngeles;

        [JsonProperty("Chicago")] public int Chicago;

        [JsonProperty("Washington_DC")] public int WashingtonDc;

        [JsonProperty("Seattle")] public int Seattle;

        [JsonProperty("London")] public int London;

        [JsonProperty("Frankfurt")] public int Frankfurt;

        [JsonProperty("Sao_Paulo")] public int SaoPaulo;

        [JsonProperty("Tokyo")] public int Tokyo;

        [JsonProperty("Sydney")] public int Sydney;

        [JsonProperty("Singapore")] public int Singapore;

        [JsonProperty("Mumbai")] public int Mumbai;

        // create a + operator
        public static HathoraPingTimes operator +(HathoraPingTimes a, HathoraPingTimes b)
        {
            return new HathoraPingTimes
            {
                LosAngeles = a.LosAngeles + b.LosAngeles,
                Chicago = a.Chicago + b.Chicago,
                WashingtonDc = a.WashingtonDc + b.WashingtonDc,
                Seattle = a.Seattle + b.Seattle,
                London = a.London + b.London,
                Frankfurt = a.Frankfurt + b.Frankfurt,
                SaoPaulo = a.SaoPaulo + b.SaoPaulo,
                Tokyo = a.Tokyo + b.Tokyo,
                Sydney = a.Sydney + b.Sydney,
                Singapore = a.Singapore + b.Singapore,
                Mumbai = a.Mumbai + b.Mumbai
            };
        }

        public static HathoraPingTimes operator /(HathoraPingTimes a, int b)
        {
            return new HathoraPingTimes
            {
                LosAngeles = a.LosAngeles / b,
                Chicago = a.Chicago / b,
                WashingtonDc = a.WashingtonDc / b,
                Seattle = a.Seattle / b,
                London = a.London / b,
                Frankfurt = a.Frankfurt / b,
                SaoPaulo = a.SaoPaulo / b,
                Tokyo = a.Tokyo / b,
                Sydney = a.Sydney / b,
                Singapore = a.Singapore / b,
                Mumbai = a.Mumbai / b
            };
        }

        public List<KeyValuePair<string, int>> GetSortedPingTimes()
        {
            var pings = new List<KeyValuePair<string, int>>
            {
                new KeyValuePair<string, int>("Los_Angeles", LosAngeles),
                new KeyValuePair<string, int>("Chicago", Chicago),
                new KeyValuePair<string, int>("Washington_DC", WashingtonDc),
                new KeyValuePair<string, int>("Seattle", Seattle),
                new KeyValuePair<string, int>("London", London),
                new KeyValuePair<string, int>("Frankfurt", Frankfurt),
                new KeyValuePair<string, int>("Sao_Paulo", SaoPaulo),
                new KeyValuePair<string, int>("Tokyo", Tokyo),
                new KeyValuePair<string, int>("Sydney", Sydney),
                new KeyValuePair<string, int>("Singapore", Singapore),
                new KeyValuePair<string, int>("Mumbai", Mumbai),
            };

            // Sort the list by ping value
            pings.Sort((firstPair, nextPair) => { return firstPair.Value.CompareTo(nextPair.Value); });

            return pings;
        }
    }
}