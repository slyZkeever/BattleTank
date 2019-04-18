// Fill out your copyright notice in the Description page of Project Settings.

//class header
#include "TankBarrel.h"
//

//additional header

//


void UTankBarrel::Elevate(float RelativeSpeed) //this could also be the cause of problem
{

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	
	auto ElevationChange = RelativeSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
	
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	
	auto ClampedElevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);
	
	SetRelativeRotation(FRotator(ClampedElevation, 0, 0));
}


