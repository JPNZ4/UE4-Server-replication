// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GoKart.generated.h"

UCLASS()
class KRAZYKARTS_API AGoKart : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGoKart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// The mass of car (kg)
	UPROPERTY(EditAnywhere)
		float Mass = 1000;
	// Force applied to car when throttle fully down (N)
	UPROPERTY(EditAnywhere)
		float MaxDrivingForce = 10000;


	float Throttle;

	FVector Velocity;

	void MoveForward(float Value);
	void UpdateLocationFromVelocity(float DeltaTime);


};
