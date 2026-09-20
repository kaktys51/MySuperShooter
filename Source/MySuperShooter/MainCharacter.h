#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "PickUpInterface.h"
#include "MainCharacter.generated.h"

constexpr ECollisionChannel ECC_InteractableTrace = ECC_GameTraceChannel3;

class UCameraComponent;
class UInputAction;
struct FInputActionValue;
class USphereComponent;

UCLASS()
class MYSUPERSHOOTER_API AMainCharacter : public ACharacter, public IPickUpInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;


	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputAction* MouseLookAction;


	void MoveInput(const FInputActionValue& Value);

	void LookInput(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void DoAim(float Yaw, float Pitch);

	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void DoMove(float Right, float Forward);

	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void DoJumpStart();

	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void DoJumpEnd();


	virtual void BeginPlay() override;

public:	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interaction")
	USphereComponent* DetectionSphere;

	FTimerHandle InteractableTraceTimerHandle;

	//Defines leght of lineTrace for interaction with objects (Better use as DetectionSphere radius)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interaction")
	float InteractableLineTraceLenght = 200.0f;

	//Sets call rate for interaction trace per second
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interaction")
	float InteractionTraceRate= 25.0f;

	//Contains All interaclable actors, used in BP to activate Linetrace
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Interaction")
	TArray<TObjectPtr<AActor>> OverlappingInteractables;

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void StartInteractableTrace();

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void StopInteractableTrace();

	UFUNCTION(BlueprintCallable)
	FHitResult LineTraceForInteractable();

	//Shell func used in timer to call LineTraceForInteractable
	UFUNCTION(BlueprintCallable)
	void InteractableTraceTick();


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
