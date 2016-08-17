// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Satellite.generated.h"

UCLASS()
class RIGIDBODY_API ASatellite : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASatellite();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Create root
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent *OurRoot;

	// Create shape
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent *OurShape;

	// 6-DoF command
	FVector CurrentLocation;
	FRotator CurrentRotation;
	FVector Velocity;
	FVector AngularVelocity;
	
};
