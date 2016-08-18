// Fill out your copyright notice in the Description page of Project Settings.

#include "RigidBody.h"
#include "RigidBodyHUD.h"
#include "Satellite.h"

ARigidBodyHUD::ARigidBodyHUD()
{
	// Use the RobotoDistanceField font from the Engine.
	static ConstructorHelpers::FObjectFinder<UFont>HUDFontOb(TEXT("/Engine/EngineFonts/RobotoDistanceField"));
	HUDFont = HUDFontOb.Object;
}

void ARigidBodyHUD::DrawHUD()
{
	// Get the rigid body states
	ASatellite* RigidBodyStates = Cast<ASatellite>(*TActorIterator<ASatellite>(GetWorld()));
	FString PositionString = FString::Printf(TEXT("Position: %10.2f, %10.2f, %10.2f"), RigidBodyStates->CurrentLocation.X, RigidBodyStates->CurrentLocation.Y, RigidBodyStates->CurrentLocation.Z);
	FString RotationString = FString::Printf(TEXT("Rotation: %10.2f, %10.2f, %10.2f"), RigidBodyStates->CurrentRotation.Roll, RigidBodyStates->CurrentRotation.Pitch, RigidBodyStates->CurrentRotation.Yaw);
	FString VelocityString = FString::Printf(TEXT("Velocity: %10.2f, %10.2f, %10.2f"), RigidBodyStates->Velocity.X, RigidBodyStates->Velocity.Y, RigidBodyStates->Velocity.Z);
	FString AngularVelString = FString::Printf(TEXT("Angular Vel.: %10.2f, %10.2f, %10.2f"), RigidBodyStates->AngularVelocity.X, RigidBodyStates->AngularVelocity.Y, RigidBodyStates->AngularVelocity.Z);
	
	// Print them
	DrawText(PositionString, FColor::White, 10, 10, HUDFont);
	DrawText(RotationString, FColor::White, 10, 30, HUDFont);
	DrawText(VelocityString, FColor::White, 10, 50, HUDFont);
	DrawText(AngularVelString, FColor::White, 10, 70, HUDFont);
}