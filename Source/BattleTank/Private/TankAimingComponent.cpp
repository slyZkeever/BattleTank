// Fill out your copyright notice in the Description page of Project Settings.

//class header
#include "TankAimingComponent.h"
//

//additional header
#include "TankBarrel.h"
//

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; //TODO should this tick?

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
		false, 
		0.0f,
		0.0f,
		ESuggestProjVelocityTraceOption::DoNotTrace //a bug occurs, if this line is not included.	 
	);

	auto Time = GetWorld()->GetTimeSeconds();


	// A crash occurs if aimed/unaimed at in-limit object, continuously.
	// crashes when barrel is moved up and down
	if(bHaveAimSolution) 
	{
		//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *GetNameSafe(GetOwner()), *AimDirection.ToString());

		auto AimDirection = OUTLaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);

		UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution found"), Time);
	}
	if (!bHaveAimSolution) //this is where the prob might be cuz this is never logged in
	{
		UE_LOG(LogTemp, Warning, TEXT("at %f, solution not found"), Time);
	}
	
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	//get the hit direction and crosshair rotation
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();

	auto AimAtRotator = AimDirection.Rotation();

	auto DeltaRotator = AimAtRotator - BarrelRotator;

	//Barrel->Elevate(5); // TODO remove magic number
	Barrel->Elevate(DeltaRotator.Pitch); // TODO remove magic number
}

/*
auto BarrelLocation = Barrel->GetComponentLocation();
UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"), *GetNameSafe(GetOwner()), *HitLocation.ToString(), *BarrelLocation.ToString());
*/

