// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PlayerData.h"

#include "ReverteranceGameInstance.generated.h"

/**
 * This game instance is used to facilitate the PlayerData used for inventory purposes. 
 * It will also facilitate SQL operations on startup and shutdown.
 */
UCLASS()
class REVERTANCE_API UReverteranceGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	// PlayerData Instance
	UPROPERTY(BlueprintReadWrite, category = "Inventory")
	class UPlayerData* playerdata;

	// Used to get the PlayerData Instance
	UFUNCTION(BlueprintCallable, category = "Inventory")
	class UPlayerData* getPlayerData();

	// Used to set the PlayerData Instance
	UFUNCTION(BlueprintCallable, category = "Inventory")
	void setPlayerData(class UPlayerData* newPlayerData);


	// Used for initializing the game instance
	void Init() override;
};
