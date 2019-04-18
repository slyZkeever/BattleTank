// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//additional header
#include "Math/UnrealMathUtility.h"


//default header
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

//including this makes this component "BlueprintSpawnableComponent"
UCLASS(meta = (BlueprintSpawnableComponent))


class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//-180 for min value and +180 for max
	void Rotate(float RelativeSpeed);


private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreePerSecond = 5;
	
};
