// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionInterface.h"
#include "PuzzlePlatforms_GI.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatforms_GI : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:
		UPuzzlePlatforms_GI(const FObjectInitializer& ObjectInitializer);

		UFUNCTION(BlueprintCallable, Category = "Setup")
		void LoadMenu();

		UFUNCTION(BlueprintCallable, Category = "Setup")
		void InGameLoadMenu();

		virtual void Init();

		UFUNCTION(Exec) //Can be called from console while playing as developer cheat kinda like scry menu
		void Host(FString ServerName) override;

		UFUNCTION(Exec)
		void Join(uint32 Index) override;

		virtual void LoadMainMenu() override;

		void RefreshServerList() override;

		UPROPERTY(EditAnywhere)
		TAssetPtr<UWorld> LobbyLevel;

		void StartSession();

private:

	TSubclassOf<class UUserWidget> MenuClass;

	TSubclassOf<class UUserWidget> InGameMenuClass;

	class UMainMenu* Menu;

	IOnlineSessionPtr SessionInterface;

	void OnCreateSessionComplete(FName SessionName, bool Success);

	void OnDestroySessionComplete(FName SessionName, bool Success);

	void OnFindSessionsComplete(bool Success);

	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	FString DesiredServerName;

	void CreateSession();

	TSharedPtr<class FOnlineSessionSearch> SessionSearch;
};
