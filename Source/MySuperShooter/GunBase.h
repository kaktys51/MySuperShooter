#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GunBase.generated.h"

class UStaticMeshComponent;

UCLASS()
class MYSUPERSHOOTER_API AGunBase : public AActor
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
