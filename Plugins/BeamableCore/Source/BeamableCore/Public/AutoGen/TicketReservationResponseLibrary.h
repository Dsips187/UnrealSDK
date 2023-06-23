#pragma once

#include "CoreMinimal.h"
#include "BeamableCore/Public/AutoGen/TicketReservationResponse.h"

#include "TicketReservationResponseLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UTicketReservationResponseLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - TicketReservationResponse To JSON String")
	static FString TicketReservationResponseToJsonString(const UTicketReservationResponse* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make TicketReservationResponse", meta=(DefaultToSelf="Outer", AdvancedDisplay="Tickets, Outer", NativeMakeFunc))
	static UTicketReservationResponse* Make(FOptionalArrayOfTicket Tickets, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break TicketReservationResponse", meta=(NativeBreakFunc))
	static void Break(const UTicketReservationResponse* Serializable, FOptionalArrayOfTicket& Tickets);
};