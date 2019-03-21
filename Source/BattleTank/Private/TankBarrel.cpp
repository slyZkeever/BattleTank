// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float BarrelSpeed)
{
	//find the current direction of barrel
	UE_LOG(LogTemp, Warning, TEXT("Elevate called with speed: %f"), BarrelSpeed);
	//if the barrel direction is not same as hit direction move it into that direction with constant angle per frame
}
