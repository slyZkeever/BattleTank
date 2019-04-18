// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//additional header
#include "Math/UnrealMathUtility.h"

//default header
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"
//



//info of barrel
UCLASS(meta = (BlueprintSpawnableComponent))
/*ClassGroup = (Custom), hidecategories = ("Collision")*/

class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	//-1 for min value and +1 for max
	void Elevate(float RelativeSpeed);

	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreePerSecond = 5;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevation = 40;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevation = 0;
};
