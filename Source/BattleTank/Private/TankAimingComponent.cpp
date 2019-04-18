// Fill out your copyright notice in the Description page of Project Settings.

//class header
#include "TankAimingComponent.h"
//

//additional header
#include "TankBarrel.h"
#include "TankTurret.h"
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

void UTankAimingComponent::SetTurretReference(UTankTurret * TurretToSet)
{
	Turret = TurretToSet;
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

	
	// A crash occurs if aimed/unaimed at in-limit object, continuously.
	// crashes when barrel is moved up and down
	if(bHaveAimSolution) 
	{
		//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *GetNameSafe(GetOwner()), *AimDirection.ToString());

		FVector AimDirection = OUTLaunchVelocity.GetSafeNormal();

		float Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution found"), Time);
		
		MoveBarrel(AimDirection);

	}
	else //this is where the prob might be cuz this is never logged in
	{
		float Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("at %f, solution not found"), Time);
	}
	
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	FRotator AimAtRotator = AimDirection.Rotation();
	
	//get the hit direction and crosshair rotation
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();

	FRotator BarrelDeltaRotator = AimAtRotator - BarrelRotator;


	FRotator TurretRotator = Turret->GetForwardVector().Rotation();

	FRotator TurretDeltaRotator = AimAtRotator - TurretRotator;

	
	//UE_LOG(LogTemp, Warning, TEXT("moving barrel"));
	
	Barrel->Elevate(BarrelDeltaRotator.Pitch);

	Turret->Rotate(TurretDeltaRotator.Yaw);
}

/*
auto BarrelLocation = Barrel->GetComponentLocation();
UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"), *GetNameSafe(GetOwner()), *HitLocation.ToString(), *BarrelLocation.ToString());
*/

