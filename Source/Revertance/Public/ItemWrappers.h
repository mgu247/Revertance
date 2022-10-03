// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ItemWrappers.generated.h"

USTRUCT(BlueprintType)
struct FAbilityWrapper {
	GENERATED_BODY()
	// Ability ID to reference in the data table
	UPROPERTY(BlueprintReadWrite, category = "Inventory")
	int32 abilityId;

	UPROPERTY(BlueprintReadWrite, category = "Inventory")
	int32 durability = 100;
};
