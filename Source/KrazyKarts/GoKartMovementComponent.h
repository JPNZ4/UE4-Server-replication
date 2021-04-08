// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GoKartMovementComponent.generated.h"

USTRUCT()
struct FGoKartMove
{
	GENERATED_BODY();

	UPROPERTY()
		float Throttle;
	UPROPERTY()
		float SteeringThrow;
	UPROPERTY()
		float DeltaTime;
	UPROPERTY()
		float Time;
};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class KRAZYKARTS_API UGoKartMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	// Sets default values for this component's properties
	UGoKartMovementComponent();

	void SimulateMove(const FGoKartMove& Move);
	FGoKartMove CreateMove(float DeltaTime);

	FVector GetAirResistance();
	FVector GetRollingResistance();

	FVector GetVelocity() { return Velocity; };
	void SetVelocity(FVector UpdatedVelocity) { Velocity = UpdatedVelocity; };
	void SetThrottle(float UpdatedThrottle) { Throttle = UpdatedThrottle; };
	void SetSteeringThrow(float UpdatedSteeringThrow) { SteeringThrow = UpdatedSteeringThrow; };

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	
	void ApplyRotation(float DeltaTime, float MoveSteeringThrow);
	void UpdateLocationFromVelocity(float DeltaTime);

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

	FVector Velocity;
	float Throttle;
	float SteeringThrow;
};
