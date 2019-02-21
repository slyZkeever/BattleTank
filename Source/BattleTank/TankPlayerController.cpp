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

ATank* ATankPlayerController::GetTankController() const
{
	return Cast<ATank>(GetPawn());
}
