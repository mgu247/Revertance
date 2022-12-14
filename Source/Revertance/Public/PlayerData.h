// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArmorWrapper.h"
#include "AbilityWrapper.h"
#include "WeaponWrapper.h"


#include "PlayerData.generated.h"

/**
 * This class holds the inventory data of the player.
 */
UCLASS()
class REVERTANCE_API UPlayerData : public UObject
{
	GENERATED_BODY()
public:
	// Constructor
	UPlayerData();

	// stores all the abilities of the user
	UPROPERTY(BlueprintReadWrite, category = "Inventory")
	TArray<struct FAbilityWrapper> abilities;

	// stores all the abilities of the user
	UPROPERTY(BlueprintReadWrite, category = "Inventory")
	TArray<struct FWeaponWrapper> weapons;

	// stores all the abilities of the user
	UPROPERTY(BlueprintReadWrite, category = "Inventory")
	TArray<struct FArmorWrapper> armors;

	// stores the balance of the user in $
	UPROPERTY(BlueprintReadWrite, category = "Balance")
	int32 balance;

	// stores the equipped ability of the user
	UPROPERTY(BlueprintReadWrite, category = "Inventory")
	struct FAbilityWrapper equippedAbility = FAbilityWrapper();

	// stores the equipped weapon of the user
	UPROPERTY(BlueprintReadWrite, category = "Inventory")
	struct FWeaponWrapper equippedWeapon = FWeaponWrapper();
	
	// stores the equipped armor of the user
	UPROPERTY(BlueprintReadWrite, category = "Inventory")
	struct FArmorWrapper equippedArmor = FArmorWrapper();

	// used to assign unique item IDs
	int32 instanceIdGenerator = 0;

	// max level
	UPROPERTY(BlueprintReadWrite, category = "Inventory")
	int32 maxLevel = 0;

	// health obtained from killing bosses
	UPROPERTY(BlueprintReadWrite, category = "Boss")
	int32 bonusBossHealth = 0;

	// attack obtained from killing bosses
	UPROPERTY(BlueprintReadWrite, category = "Boss")
	int32 bonusBossAttack = 0;

	// defense obtained from killing bosses
	UPROPERTY(BlueprintReadWrite, category = "Boss")
	int32 bonusBossDefense = 0;


	// Used to add an Ability without cost. Typically used at the end of levels
	UFUNCTION(BlueprintCallable, category = "Inventory")
	void addAbility(int32 itemId);

	// Used to buy an Ability. Gives the player the Ability at a cost for the currency
	UFUNCTION(BlueprintCallable, category = "Inventory")
	bool buyAbility(int32 itemId, int32 price);

	// Obtain all the Abilities the player owns
	UFUNCTION(BlueprintCallable, category = "Inventory")
	TArray<struct FAbilityWrapper> getAbilities();

	// Sets the Abilities of the player
	UFUNCTION(BlueprintCallable, category = "Inventory")
	void setAbilities(TArray<struct FAbilityWrapper> newAbilities);

	// Obtain the Ability with the given instance ID
	UFUNCTION(BlueprintCallable, category = "Inventory")
	struct FAbilityWrapper getAbilityFromInstanceId(int32 instanceId);

	// Used to add a Weapon without cost. Typically used at the end of levels
	UFUNCTION(BlueprintCallable, category = "Inventory")
	void addWeapon(int32 itemId);

	// Used to buy a Weapon. Gives the player the Weapon at a cost for the currency
	UFUNCTION(BlueprintCallable, category = "Inventory")
	bool buyWeapon(int32 itemId, int32 price);

	// Obtain all the Weapons the player owns
	UFUNCTION(BlueprintCallable, category = "Inventory")
	TArray<struct FWeaponWrapper> getWeapons();

	// Sets the Weapons of the player
	UFUNCTION(BlueprintCallable, category = "Inventory")
	void setWeapons(TArray<struct FWeaponWrapper> newWeapons);

	// Obtain the Weapon with the given instance ID
	UFUNCTION(BlueprintCallable, category = "Inventory")
	struct FWeaponWrapper getWeaponFromInstanceId(int32 instanceId);

	// Used to add an Armor without cost. Typically used at the end of levels
	UFUNCTION(BlueprintCallable, category = "Inventory")
	void addArmor(int32 itemId);

	// Used to buy an Armor. Gives the player the Armor at a cost for the currency
	UFUNCTION(BlueprintCallable, category = "Inventory")
	bool buyArmor(int32 itemId, int32 price);

	// Obtain all the Armors the player owns
	UFUNCTION(BlueprintCallable, category = "Inventory")
	TArray<struct FArmorWrapper> getArmors();

	// Sets the Armprs of the player
	UFUNCTION(BlueprintCallable, category = "Inventory")
	void setArmors(TArray<struct FArmorWrapper> newArmors);

	// Obtain the Armor with the given instance ID
	UFUNCTION(BlueprintCallable, category = "Inventory")
	struct FArmorWrapper getArmorFromInstanceId(int32 instanceId);

	// Used to set the balance
	UFUNCTION(BlueprintCallable, category = "Balance")
	void setBalance(int32 newBalance);

	// Used to get the balance
	UFUNCTION(BlueprintCallable, category = "Balance")
	int32 getBalance();

	// Checks if there is enough balance to buy the item
	UFUNCTION(BlueprintCallable, category = "Balance")
	bool enoughBalance(int32 price);

	// Equips a weapon
	UFUNCTION(BlueprintCallable, category = "Inventory")
	void equipWeapon(struct FWeaponWrapper newWeapon);

	// Dequips a weapon
	UFUNCTION(BlueprintCallable, category = "Inventory")
	void dequipWeapon();

	// Returns equipped weapon
	UFUNCTION(BlueprintCallable, category = "Inventory")
	struct FWeaponWrapper getEquippedWeapon();

	// Equips an ability
	UFUNCTION(BlueprintCallable, category = "Inventory")
	void equipAbility(struct FAbilityWrapper newAbility);

	// Dequips a ability
	UFUNCTION(BlueprintCallable, category = "Inventory")
	void dequipAbility();

	// Returns equipped ability
	UFUNCTION(BlueprintCallable, category = "Inventory")
	struct FAbilityWrapper getEquippedAbility();

	// Equips an armor
	UFUNCTION(BlueprintCallable, category = "Inventory")
	void equipArmor(struct FArmorWrapper newArmor);

	// Dequips a weapon
	UFUNCTION(BlueprintCallable, category = "Inventory")
	void dequipArmor();

	// Returns equipped armor
	UFUNCTION(BlueprintCallable, category = "Inventory")
	struct FArmorWrapper getEquippedArmor();


	// Gets the max level
	UFUNCTION(BlueprintCallable, category = "Inventory")
	int32 getMaxLevel();

	// Sets the max level
	UFUNCTION(BlueprintCallable, category = "Inventory")
	void setMaxLevel(int32 newLevel);

	// Gets the currently available weapon IDs
	UFUNCTION(BlueprintCallable, category = "Inventory")
	TArray<int32> getSellableWeapons();

	// Gets the currently available ability IDs
	UFUNCTION(BlueprintCallable, category = "Inventory")
	TArray<int32> getSellableAbilities();

	// Gets the currently available armor IDs
	UFUNCTION(BlueprintCallable, category = "Inventory")
	TArray<int32> getSellableArmors();

	// Get Bonus Boss Health
	UFUNCTION(BlueprintCallable, category = "Boss")
	int32 getBonusBossHealth();

	// Set Bonus Boss Health
	UFUNCTION(BlueprintCallable, category = "Boss")
	void setBonusBossHealth(int32 newBonusBossHealth);

	// Get Bonus Boss Attack
	UFUNCTION(BlueprintCallable, category = "Boss")
	int32 getBonusBossAttack();

	// Set Bonus Boss Attack
	UFUNCTION(BlueprintCallable, category = "Boss")
	void setBonusBossAttack(int32 newBonusBossAttack);

	// Get Bonus Boss Defense
	UFUNCTION(BlueprintCallable, category = "Boss")
	int32 getBonusBossDefense();

	// Set Bonus Boss Health
	UFUNCTION(BlueprintCallable, category = "Boss")
	void setBonusBossDefense(int32 newBonusBossDefense);


	// Sets up the inventory for tutorial purposes
	UFUNCTION(BlueprintCallable, category = "Inventory")
	void initializeTutorialInventory();
};
