#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpInterface.h"
#include "GunBase.generated.h"

class UStaticMeshComponent;

UCLASS()
class MYSUPERSHOOTER_API AGunBase : public AActor, public IPickUpInterface
{
	GENERATED_BODY()
	
public:	
	AGunBase();

protected:
	virtual void BeginPlay() override;

public:	
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Components")
	UStaticMeshComponent* GunMesh;

	virtual void Tick(float DeltaTime) override;

};
