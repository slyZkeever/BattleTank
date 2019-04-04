// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//find the current direction of barrel
	//UE_LOG(LogTemp, Warning, TEXT("Elevate called with speed: %f"), RelativeSpeed);
	//if the barrel direction is not same as hit direction move it into that direction with constant angle per frame

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);

	auto ElevationChange = RelativeSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
	
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	auto ClampedElevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);
	
	SetRelativeRotation(FRotator(ClampedElevation, 0, 0));
}
