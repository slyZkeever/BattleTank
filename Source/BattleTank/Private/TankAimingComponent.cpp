// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float FireSpeed)
{
	if (!Barrel) { return; } //protecting the pointer
	
	FVector OUTLaunchVelocity; //set to 0
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile")); //socket added to barrel's mesh

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OUTLaunchVelocity,
		StartLocation,
		HitLocation,
		FireSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if(bHaveAimSolution)
	{
		auto AimDirection = OUTLaunchVelocity.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *GetNameSafe(GetOwner()), *AimDirection.ToString());
		MoveBarrel(AimDirection);
	}
	
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	//get the hit direction and crosshair rotation
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAtRotator = AimDirection.Rotation();

	auto DeltaRotator = AimAtRotator - BarrelRotator;
	Barrel->Elevate(5);

	
}

/*
auto BarrelLocation = Barrel->GetComponentLocation();
UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"), *GetNameSafe(GetOwner()), *HitLocation.ToString(), *BarrelLocation.ToString());
*/

