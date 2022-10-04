// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "AbilityWrapper.generated.h"

/**
 * Wrapper class for Ability that contains instance specific information
 */
USTRUCT(BlueprintType)
struct FAbilityWrapper {
	GENERATED_BODY()

	// Ability ID corresponding to data table
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	int32 abilityId = -1;

	// Instance ID corresponding to this unique instance of the weapon
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	int32 instanceId = -1;

	// Durability
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	int32 durability = 100;

	bool operator==(const FAbilityWrapper& rightAbility) const {
		return instanceId == rightAbility.instanceId;
	}
};
