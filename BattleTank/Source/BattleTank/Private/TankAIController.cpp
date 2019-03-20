// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	ATank* thisTank = GetControlledTank();

	if (!thisTank) {
		UE_LOG(LogTemp, Warning, TEXT("Could not find AI tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI:%s"), *thisTank->GetName());
	}

	ATank* PC = GetPlayerTank();

	if (!PC) {
		UE_LOG(LogTemp, Warning, TEXT("Could not find player"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI:%s found player:%s"), *thisTank->GetName(), *PC->GetName());
	}

}

ATank* ATankAIController :: GetControlledTank() const {
	return ((ATank*)GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {	
	return ((ATank*)GetWorld()->GetFirstPlayerController()->GetPawn());
}