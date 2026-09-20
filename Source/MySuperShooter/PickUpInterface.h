
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PickUpInterface.generated.h"

UINTERFACE(MinimalAPI)
class UPickUpInterface : public UInterface
{
	GENERATED_BODY()
};


class MYSUPERSHOOTER_API IPickUpInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Pickup")
	void TryPickUp(AActor* Picker);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Pickup")
	void ConfirmPickedUp(AActor* PickedUp);
};
