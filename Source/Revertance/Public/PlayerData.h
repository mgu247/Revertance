// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemWrappers.h"

#include "PlayerData.generated.h"

/**
 * This class holds the inventory data of the player.
 */
UCLASS()
class REVERTANCE_API UPlayerData : public UObject
{
	GENERATED_BODY()
public:
	// stores all the abilities of the user
	UPROPERTY(BlueprintReadWrite, category = "Inventory")
	TArray<struct FAbilityWrapper> abilities;

	// stores the balance of the user in $
	UPROPERTY(BlueprintReadWrite, category = "Balance")
	int32 balance;



	// Used to add an Ability without cost. Typically used at the end of levels
	UFUNCTION(BlueprintCallable, category = "Inventory")
	void addAbility(int32 itemId);

	// Used to buy an Ability. Gives the player the Ability at a cost for the currency
	UFUNCTION(BlueprintCallable, category = "Inventory")
	bool buyAbility(int32 itemId, int32 price);

	// Obtain all the Abilities the player owns
	UFUNCTION(BlueprintCallable, category = "Inventory")
	TArray<struct FAbilityWrapper> getAbilities();

	// Used to set the balance
	UFUNCTION(BlueprintCallable, category = "Balance")
	void setBalance(int32 newBalance);

	// Used to get the balance
	UFUNCTION(BlueprintCallable, category = "Balance")
	int32 getBalance();

	// Checks if there is enough balance to buy the item
	UFUNCTION(BlueprintCallable, category = "Balance")
	bool enoughBalance(int32 price);
};
