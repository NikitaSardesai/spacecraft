// Fill out your copyright notice in the Description page of Project Settings.

#include "RigidBody.h"
#include "Satellite.h"


// Sets default values
ASatellite::ASatellite()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Root component is a sphere that reacts to physics
	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(10.0f);
	OurRoot = SphereComponent;

	// Static Mesh of our Sphere
	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Shape"));
	SphereVisual->AttachTo(RootComponent);
	OurShape = SphereVisual;
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Props/SM_Rock.SM_Rock"));
	if (SphereVisualAsset.Succeeded()) {
		SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
		SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		SphereVisual->SetWorldScale3D(FVector(1.0f));

		// Set collision
		SphereVisual->BodyInstance.SetCollisionProfileName("BlockAll");
		SphereVisual->SetNotifyRigidBodyCollision(true);
		SphereVisual->SetSimulatePhysics(false);
	}

}

// Called when the game starts or when spawned
void ASatellite::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASatellite::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	// Get current location and rotation
	CurrentLocation = GetActorLocation();
	CurrentRotation = GetActorRotation();

	// Calculate desired translational and angular velocity
	Velocity = FVector(10.0f, 10.0f, 0.0f);
	AngularVelocity = FVector(2.0f, 1.0f, 5.0f);


	// Move it (just a test for now)
	CurrentLocation.X += Velocity.X * DeltaTime;
	CurrentLocation.Y += Velocity.Y * DeltaTime;
	CurrentLocation.Z += Velocity.Z * DeltaTime;

	// Rotate it (just a test for now)
	CurrentRotation.Roll += AngularVelocity.X * DeltaTime;
	CurrentRotation.Pitch += AngularVelocity.Y * DeltaTime;
	CurrentRotation.Yaw += AngularVelocity.Z * DeltaTime;

	SetActorLocation(CurrentLocation);
	SetActorRotation(CurrentRotation);

	// Print info	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Angular Velocity: %f, %f, %f"), AngularVelocity.X, AngularVelocity.Y, AngularVelocity.Z));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Velocity: %f, %f, %f"), Velocity.X, Velocity.Y, Velocity.Z));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Rotation: %f, %f, %f"), CurrentRotation.Roll, CurrentRotation.Pitch, CurrentRotation.Yaw));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Position: %f, %f, %f"), CurrentLocation.X, CurrentLocation.Y, CurrentLocation.Z));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("***"), CurrentLocation.X, CurrentLocation.Y, CurrentLocation.Z));
	
}	
