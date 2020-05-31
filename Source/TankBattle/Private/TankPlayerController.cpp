// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "TankBattle.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not Possesing a Tank"));
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Possesing %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();

}


void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; //OUT parameter

	if (GetSightRayHitLocation(HitLocation))
		{
			//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());

			//tell controlled tank to aim at this point
		}
}


ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	FVector LookDirection;
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	if (GetLookDirection(ScreenLocation, LookDirection))
		{	
			//line trace along that look direction, and see what we hit (up to max range)
			//GetLookVectorHitLocation
		
		}
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{	
	FVector WorldPosition; // delete
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldPosition, LookDirection);
}