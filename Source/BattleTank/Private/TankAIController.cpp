// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "../Public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player not found"));
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("AI found player: %s"), *PlayerTank->GetName());
}

ATank * ATankAIController::GetPlayerTank()
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr;}
	return Cast<ATank>(PlayerPawn);
}


ATank* ATankAIController::GetTankController() const
{
	return Cast<ATank>(GetPawn());
}


