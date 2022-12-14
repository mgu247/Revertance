// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerData.h"


UPlayerData::UPlayerData() {
	balance = 1400;
}

void UPlayerData::addAbility(int32 itemId) {
	struct FAbilityWrapper newAbilityWrapper = FAbilityWrapper();
	newAbilityWrapper.abilityId = itemId;
	newAbilityWrapper.instanceId = instanceIdGenerator;
	instanceIdGenerator++;

	abilities.Emplace(newAbilityWrapper);
}

bool UPlayerData::buyAbility(int32 itemId, int32 price) {
	if (enoughBalance(price)) {
		balance -= price;

		addAbility(itemId);
		return true;
	}
	return false;
}

TArray<struct FAbilityWrapper> UPlayerData::getAbilities() {
	return abilities;
}

void UPlayerData::setAbilities(TArray<struct FAbilityWrapper> newAbilities) {
	dequipAbility();

	abilities = newAbilities;
}

struct FAbilityWrapper UPlayerData::getAbilityFromInstanceId(int32 instanceId) {
	for (struct FAbilityWrapper ability : abilities) {
		if (ability.instanceId == instanceId) {
			return ability;
		}
	}
	return FAbilityWrapper();
}

void UPlayerData::addWeapon(int32 itemId) {
	struct FWeaponWrapper newWeaponWrapper = FWeaponWrapper();
	newWeaponWrapper.weaponId = itemId;
	newWeaponWrapper.instanceId = instanceIdGenerator;
	instanceIdGenerator++;

	weapons.Emplace(newWeaponWrapper);
}

bool UPlayerData::buyWeapon(int32 itemId, int32 price) {
	if (enoughBalance(price)) {
		balance -= price;

		addWeapon(itemId);
		return true;
	}
	return false;
}

TArray<struct FWeaponWrapper> UPlayerData::getWeapons() {
	return weapons;
}

void UPlayerData::setWeapons(TArray<struct FWeaponWrapper> newWeapons) {
	dequipWeapon();

	weapons = newWeapons;
}

struct FWeaponWrapper UPlayerData::getWeaponFromInstanceId(int32 instanceId) {
	for (struct FWeaponWrapper weapon : weapons) {
		if (weapon.instanceId == instanceId) {
			return weapon;
		}
	}
	return FWeaponWrapper();
}

void UPlayerData::addArmor(int32 itemId) {
	struct FArmorWrapper newArmorWrapper = FArmorWrapper();
	newArmorWrapper.armorId = itemId;
	newArmorWrapper.instanceId = instanceIdGenerator;
	instanceIdGenerator++;

	armors.Emplace(newArmorWrapper);
}

bool UPlayerData::buyArmor(int32 itemId, int32 price) {
	if (enoughBalance(price)) {
		balance -= price;

		addArmor(itemId);
		return true;
	}
	return false;
}

TArray<struct FArmorWrapper> UPlayerData::getArmors() {
	return armors;
}

void UPlayerData::setArmors(TArray<struct FArmorWrapper> newArmors) {
	dequipArmor();

	armors = newArmors;
}

struct FArmorWrapper UPlayerData::getArmorFromInstanceId(int32 instanceId) {
	for (struct FArmorWrapper armor : armors) {
		if (armor.instanceId == instanceId) {
			return armor;
		}
	}
	return FArmorWrapper();
}

void UPlayerData::setBalance(int32 newBalance) {
	balance = newBalance;
}

int32 UPlayerData::getBalance() {
	return balance;
}

bool UPlayerData::enoughBalance(int32 price) {
	return balance >= price;
}

void UPlayerData::equipWeapon(struct FWeaponWrapper newWeapon) {
	dequipWeapon();
	struct FWeaponWrapper weaponToRemove = FWeaponWrapper();
	for (struct FWeaponWrapper weapon : weapons) {
		if (weapon == newWeapon) {
			weaponToRemove = weapon;
		}
	}

	if (weaponToRemove.instanceId != -1) {
		weapons.Remove(weaponToRemove);
	}

	equippedWeapon = newWeapon;
}

void UPlayerData::dequipWeapon() {
	if (equippedWeapon.instanceId != -1) {
		weapons.Add(equippedWeapon);
	}
	equippedWeapon = FWeaponWrapper();
}

struct FWeaponWrapper UPlayerData::getEquippedWeapon() {
	return equippedWeapon;
}

void UPlayerData::equipAbility(struct FAbilityWrapper newAbility) {
	dequipAbility();
	struct FAbilityWrapper abilityToRemove = FAbilityWrapper();
	for (struct FAbilityWrapper ability: abilities) {
		if (ability == newAbility) {
			abilityToRemove = ability;
		}
	}

	if (abilityToRemove.instanceId != -1) {
		abilities.Remove(abilityToRemove);
	}

	equippedAbility = newAbility;
}

void UPlayerData::dequipAbility() {
	if (equippedAbility.instanceId != -1) {
		abilities.Add(equippedAbility);
	}
	equippedAbility = FAbilityWrapper();
}

struct FAbilityWrapper UPlayerData::getEquippedAbility() {
	return equippedAbility;
}

void UPlayerData::equipArmor(struct FArmorWrapper newArmor) {
	dequipArmor();
	struct FArmorWrapper armorToRemove = FArmorWrapper();
	for (struct FArmorWrapper armor : armors) {
		if (armor == newArmor) {
			armorToRemove = armor;
		}
	}

	if (armorToRemove.instanceId != -1) {
		armors.Remove(armorToRemove);
	}

	equippedArmor = newArmor;
}

void UPlayerData::dequipArmor() {
	if (equippedArmor.instanceId != -1) {
		armors.Add(equippedArmor);
	}
	equippedArmor = FArmorWrapper();
}

struct FArmorWrapper UPlayerData::getEquippedArmor() {
	return equippedArmor;
}

void UPlayerData::initializeTutorialInventory() {
	dequipWeapon();
	dequipAbility();
	dequipArmor();

	addWeapon(1); // Heavy cannon
	addAbility(2); // Behemoth Rune
	addArmor(2); // Cloak of Flames
}

int32 UPlayerData::getMaxLevel() {
	return maxLevel;
}

void UPlayerData::setMaxLevel(int32 newLevel) {
	maxLevel = newLevel;
}

TArray<int32> UPlayerData::getSellableWeapons() {
	TArray<int32> forSale;
	if (maxLevel == 0) {
		forSale = { 1, 2, 3 };
		return forSale;
	}
	else if (maxLevel == 1) {
		forSale = { 1, 2, 3, 4, 5 };
		return forSale;
	}
	else {
		forSale = { 1, 2, 3, 4, 5, 6, 7 };
		return forSale;
	}
}

TArray<int32> UPlayerData::getSellableAbilities() {
	TArray<int32> forSale;
	if (maxLevel == 0) {
		forSale = { 3 };
		return forSale;
	}
	else if (maxLevel == 1) {
		forSale = { 3, 4 };
		return forSale;
	}
	else {
		forSale = { 3, 4, 1 };
		return forSale;
	}
}

TArray<int32> UPlayerData::getSellableArmors() {
	TArray<int32> forSale;
	if (maxLevel == 0) {
		forSale = { 1, 2 };
		return forSale;
	}
	else if (maxLevel == 1) {
		forSale = { 1, 2, 3, 4 };
		return forSale;
	}
	else {
		forSale = { 1, 2, 3, 4, 5, 6 };
		return forSale;
	}
}

int32 UPlayerData::getBonusBossHealth() {
	return bonusBossHealth;
}

void UPlayerData::setBonusBossHealth(int32 newBonusBossHealth) {
	bonusBossHealth = newBonusBossHealth;
}

int32 UPlayerData::getBonusBossAttack() {
	return bonusBossAttack;
}

void UPlayerData::setBonusBossAttack(int32 newBonusBossAttack) {
	bonusBossAttack = newBonusBossAttack;
}

int32 UPlayerData::getBonusBossDefense() {
	return bonusBossDefense;
}

void UPlayerData::setBonusBossDefense(int32 newBonusBossDefense) {
	bonusBossDefense = newBonusBossDefense;
}
