// Fill out your copyright notice in the Description page of Project Settings.

#include "RigidBody.h"
#include "RigidBodyGameMode.h"
#include "RigidBodyHUD.h"


ARigidBodyGameMode::ARigidBodyGameMode()
{
	// Set default HUD
	HUDClass = ARigidBodyHUD::StaticClass();
}

