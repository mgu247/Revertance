// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerData.h"


void UPlayerData::addAbility(int32 itemId) {
	struct FAbilityWrapper newAbilityWrapper = FAbilityWrapper();
	newAbilityWrapper.abilityId = itemId;

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

void UPlayerData::setBalance(int32 newBalance) {
	balance = newBalance;
}

int32 UPlayerData::getBalance() {
	return balance;
}

bool UPlayerData::enoughBalance(int32 price) {
	return balance >= price;
}