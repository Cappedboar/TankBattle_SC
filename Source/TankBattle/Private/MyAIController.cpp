// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBattle.h"
#include "MyAIController.h"

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ai Controller can't Find Player Tank"));
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Contorller Found Player: %s"), *(PlayerTank->GetName()));
	}
}

ATank* AMyAIController::GetControlledTank() const { return Cast<ATank>(GetPawn()); }

ATank* AMyAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	if (!PlayerPawn) {return nullptr;}
	return Cast<ATank>(PlayerPawn);
}