// Fill out your copyright notice in the Description page of Project Settings.

//class header
#include "../Public/TankAIController.h"
//

//additional header
#include "Tank.h"
//

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerTank = GetPlayerTank();
	
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player not found"));
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("AI found player: %s"), *PlayerTank->GetName());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (PlayerTank)
	{
		GetTankController()->AimAt(PlayerTank->GetActorLocation());
	}	
}

ATank* ATankAIController::GetTankController() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank()
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr;}
	return Cast<ATank>(PlayerPawn);
}






