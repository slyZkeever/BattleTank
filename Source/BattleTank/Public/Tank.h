// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//additional headers
#include "Components/StaticMeshComponent.h"
//

//default headers
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"
//

//forward declarations
class UTankBarrel;  
class UTankAimingComponent;
//


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Tank) //so that it is saved after construction
	UTankAimingComponent* TankAimingComponent;
	

public:	
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Tank) //category's name will pop up in bp's details panal  
	void SetBarrelReference(UTankBarrel* BarrelToSet); //reference for static mesh 


private:
	UPROPERTY(EditAnywhere, Category = Tank)
	float FireSpeed = 1000000.f; //reference value

};
