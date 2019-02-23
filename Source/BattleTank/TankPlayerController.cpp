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
	//Get world location through line tracing at crosshair
	    //if anything hit 
	        //tell controlled tank to aim at this location    
}