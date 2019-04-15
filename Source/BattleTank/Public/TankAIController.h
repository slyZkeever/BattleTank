// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//default headers
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"
//

//forward declarations
class ATank;
//

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ATank* GetTankController() const;
	

protected:
	virtual void BeginPlay() override;

private:
	ATank* GetPlayerTank();
	ATank* PlayerTank;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
