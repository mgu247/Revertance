// Fill out your copyright notice in the Description page of Project Settings.


#include "ReverteranceGameInstance.h"

class UPlayerData* UReverteranceGameInstance::getPlayerData() {
	return playerdata;
}

void UReverteranceGameInstance::setPlayerData(class UPlayerData* newPlayerData) {
	playerdata = newPlayerData;
}