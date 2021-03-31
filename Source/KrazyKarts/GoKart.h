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
	// Full lock turning raidus (meters)
	UPROPERTY(EditAnywhere)
		float TurningRadius = 10;
	// Air Coef
	UPROPERTY(EditAnywhere)
		float DragCoefficient = 16;
	// Rolling Coef
	UPROPERTY(EditAnywhere)
		float RollingCoefficient = 0.02;

	float Throttle;
	float SteeringThrow;

	FVector Velocity;

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_MoveForward(float Value);
	UFUNCTION(Server, Reliable, WithValidation)
	void Server_MoveRight(float Value);

	void ApplyRotation(float DeltaTime);
	void UpdateLocationFromVelocity(float DeltaTime);
	FVector GetAirResistance();
	FVector GetRollingResistance();


};
