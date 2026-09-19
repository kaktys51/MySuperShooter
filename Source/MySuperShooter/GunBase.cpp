#include "GunBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"


AGunBase::AGunBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GunMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunMesh"));
	RootComponent = GunMesh;
}

void AGunBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGunBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

