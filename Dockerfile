FROM ghcr.io/epicgames/unreal-engine:dev-5.3.2 as builder

USER ue4
# use --build-arg BUILD_TYPE=server in docker build to set it to be server build
ARG BUILD_TYPE

# by default it passes all maps, you can pass value `--build-arg MAP_ARG=-map=DefaultMap+BeamBackendTests` to override it
ARG MAP_ARG=-allmaps

# Copy your Unreal project files into the Docker image
COPY --chown=ue4 . /home/ue4/project

RUN /home/ue4/UnrealEngine/Engine/Build/BatchFiles/Linux/GenerateProjectFiles.sh -projectfiles -project=/home/ue4/project/BeamableUnreal.uproject -game -rocket -progress  
RUN /home/ue4/UnrealEngine/Engine/Build/BatchFiles/RunUAT.sh BuildCookRun -project=/home/ue4/project/BeamableUnreal.uproject \
-utf8output \
-platform=Linux \
-clientconfig=Shipping \
-serverconfig=Shipping \
 $BUILD_TYPE \
-noP4 -nodebuginfo $MAP_ARG \
-cook -build -stage -prereqs -pak -archive \
-archivedirectory=/home/ue4/PackagedProject