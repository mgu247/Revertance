// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "WeaponWrapper.generated.h"

/**
 * Wrapper class for Armor that contains instance specific information
 */
USTRUCT(BlueprintType)
struct FWeaponWrapper {
	GENERATED_BODY()

	// Weapon ID corresponding to data table
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	int32 weaponId = -1;

	// Instance ID corresponding to this unique instance of the weapon
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	int32 instanceId = -1;

	// Durability
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	int32 durability = 100;

	bool operator==(const FWeaponWrapper& rightWeapon) const {
		return instanceId == rightWeapon.instanceId;
	}
};

