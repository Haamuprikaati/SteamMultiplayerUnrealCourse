// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "PuzzlePlatforms_GI.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{

	Super::PostLogin(NewPlayer);

	NumberOfPlayers++;
	if (NumberOfPlayers >= 2)
	{
		GetWorldTimerManager().SetTimer(GameStartTimer, this, &ALobbyGameMode::StartGame, GameStartWaitTime);
	}
}

void ALobbyGameMode::Logout(AController * Exiting)
{
	Super::Logout(Exiting);

	NumberOfPlayers -= 1;
	
}

void ALobbyGameMode::StartGame()
{
	auto GameInstance = Cast<UPuzzlePlatforms_GI>(GetGameInstance());

	if (GameInstance == nullptr) return;

	GameInstance->StartSession();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	bUseSeamlessTravel = true;
	World->ServerTravel(GameLevel.GetLongPackageName().Append("?listen"));
}