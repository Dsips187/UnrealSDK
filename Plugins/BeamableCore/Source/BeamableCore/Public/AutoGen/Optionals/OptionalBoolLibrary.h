

#pragma once

#include "CoreMinimal.h"
#include "AutoGen/Optionals/OptionalBool.h"

#include "OptionalBoolLibrary.generated.h"

UCLASS(BlueprintType)
class BEAMABLECORE_API UOptionalBoolLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:	

	/**
	* @brief Constructs an FOptionalBool struct from the given value.	  
	*/
	UFUNCTION(BlueprintPure, Category="Beam|Optionals", meta=(DisplayName="Beam - Make Optional Bool", NativeMakeFunc))
	static FOptionalBool MakeOptional(bool Value);

	/**
	 * @brief Converts an bool into an FOptionalBool automatically.
	 * @param Value The bool to convert.
	 * @return An optional with the Bool set as it's value.
	 */
	UFUNCTION(BlueprintPure, Category="Beam|Optionals", meta = (DisplayName = "Beam - Bool To Optional", CompactNodeTitle = "->", BlueprintAutocast))
	static FOptionalBool Conv_OptionalFromValue(bool Value);
	
	/**
	 * @brief Use this when the behavior changes based on whether or not a value is set on the optional.
	 * @param Optional The optional you wish to get data from.
	 * @param Value The value in the optional. 
	 * @return Whether or not the value was set. We provide no guarantees on what the value is if the optional is not set. 
	 */
	UFUNCTION(BlueprintCallable, Category="Beam|Optionals", meta=(DisplayName="Beam - Optional Has Value", ExpandBoolAsExecs="ReturnValue"))
	static bool HasValue(const FOptionalBool& Optional, bool& Value);

	/**
	 * @brief Use this when the behaviour doesnt change based on whether or not the value is set, instead just provide a default value instead.
	 * @param Optional The optional you wish to get data from.
	 * @param DefaultValue The value that will be set if the Optional has no value in it.
	 * @param WasSet Whether or not the value was set. When false, the return value is the given DefaultValue.   
	 * @return The default value, if the Optional IS NOT set. The optional value, otherwise.
	 */
	UFUNCTION(BlueprintPure, Category="Beam|Optionals", meta=(DisplayName="Beam - Get Optional's Bool Value"))
	static bool GetOptionalValue(const FOptionalBool& Optional, bool DefaultValue, bool& WasSet);

	
};