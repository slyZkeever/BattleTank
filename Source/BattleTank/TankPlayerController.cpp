// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
		
	auto Tank = GetTankController();

	if (Tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Tank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Pawn not found"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimAtCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("Tick working"));
}



ATank* ATankPlayerController::GetTankController() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimAtCrosshair()
{
	if (!GetTankController()) { return; }

	FVector HitLocation;
	
	       
	if (GetSightRayHitLocation(HitLocation)) 
	{
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
		
		//TODO tell controlled tank to aim at this location 
	}
	
}


//Get world location of line tracing hit object through crosshair, return true if hit landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//get the location of crosshair 
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX*CrosshairXLocation, ViewportSizeY*CrosshairYLocation);

	//UE_LOG(LogTemp, Warning, TEXT("Crosshair Location: %s"), *ScreenLocation.ToString());


	//pass the location of crosshair to linetracer 
	//line trace to the provided location 
	return true;
}