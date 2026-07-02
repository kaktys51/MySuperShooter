#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

class UInputMappingContext;

UCLASS()
class MYSUPERSHOOTER_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	AMainPlayerController();

protected:

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category = "Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;
};
