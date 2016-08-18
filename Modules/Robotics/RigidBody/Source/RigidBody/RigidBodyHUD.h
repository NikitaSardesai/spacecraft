// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "RigidBodyHUD.generated.h"

/**
 * 
 */
UCLASS()
class RIGIDBODY_API ARigidBodyHUD : public AHUD
{
	GENERATED_BODY()

	// Sets default values for this HUD
	ARigidBodyHUD();
	
	/** Variable for storing the font. */
	UPROPERTY()
	UFont* HUDFont;

	/** Primary draw call for the HUD. */
	virtual void DrawHUD() override;
	
	
};
