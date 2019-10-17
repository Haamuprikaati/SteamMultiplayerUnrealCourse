// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"

USTRUCT()
struct FServerData
{
	GENERATED_BODY()

	FString Name;
	uint16 CurrentPlayers;
	uint16 MaxPlayers;
	FString HostUsername;
};

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

public:

	UMainMenu(const FObjectInitializer& ObjectInitializer);

	void SetServerList(TArray<FServerData> ServerNames);

	void SelectIndex(uint32 Index);

protected:

		virtual bool Initialize();

private:

		UPROPERTY(meta = (BindWidget))
		class UWidgetSwitcher* MenuSwitcher;

		//Located in Main Menu
		UPROPERTY(meta = (BindWidget))
		class UButton* HostButton;

		UPROPERTY(meta = (BindWidget))
		class UButton* JoinButton;

		UPROPERTY(meta = (BindWidget))
		class UButton* QuitGameButton;

		UPROPERTY(meta = (BindWidget))
		class UWidget* JoinMenu;

		UPROPERTY(meta = (BindWidget))
		class UWidget* HostMenu;

		UFUNCTION()
		void OpenJoinMenu();

		UFUNCTION()
		void OpenHostMenu();

		UFUNCTION()
		void QuitGame();

		//Used Join Menu
		UPROPERTY(meta = (BindWidget))
		class UButton* BackButton;

		UPROPERTY(meta = (BindWidget))
		class UButton* JoinGameButton;

		UPROPERTY(meta = (BindWidget))
		class UPanelWidget* ServerList;

		UFUNCTION()
		void OpenMainMenu();

		UPROPERTY(meta = (BindWidget))
		class UWidget* MainMenu;

		UFUNCTION()
		void JoinServer();

		TSubclassOf<class UUserWidget> ServerRowClass;

		TOptional<uint32> SelectedIndex;

		void UpdateChildren();

		//Used in Host Menu

		UFUNCTION()
		void HostServer();

		UPROPERTY(meta = (BindWidget))
		class UButton* HostGameButton;

		UPROPERTY(meta = (BindWidget))
		class UButton* BackHostButton;

		UPROPERTY(meta = (BindWidget))
		class UEditableTextBox* ServerHostName;
		

};
