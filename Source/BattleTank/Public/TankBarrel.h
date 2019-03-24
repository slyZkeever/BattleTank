// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

//info of barrel

UCLASS(meta = (BlueprintSpawnableComponent))
/*ClassGroup = (Custom), hidecategories = ("Collision")*/

class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float BarrelSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MoveDegreePerSecond = 20.f;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevation = 40.f;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevation = 0.f;
};
