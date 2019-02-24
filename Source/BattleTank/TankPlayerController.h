// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private: //for functions

	
	void AimAtCrosshair();	//aim turret at this location to fire

	ATank* GetTankController() const;
	
	bool GetSightRayHitLocation(FVector& HitLocation) const;

private: //for variables 

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.5f;
	
};
