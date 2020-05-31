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

ATank* ATankPlayerController::GetControlledTank() const {return Cast<ATank>(GetPawn());}



