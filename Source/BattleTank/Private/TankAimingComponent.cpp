// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
	
	OurTankName = GetOwner()->GetName();
	//UE_LOG(LogTemp, Warning, TEXT("Position Report reporting on %s"), *OurTankName);
		
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//UE_LOG(LogTemp, Warning, TEXT("got owner: %s"), *OurTankName);
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	UE_LOG(LogTemp, Warning, TEXT("got owner: %s"), *OurTankName);

	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *OurTankName, *HitLocation.ToString());
}
	


void UTankAimingComponent::Test()
{
	//UE_LOG(LogTemp, Warning, TEXT("into test function"));
}

