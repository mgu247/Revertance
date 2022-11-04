// Fill out your copyright notice in the Description page of Project Settings.


#include "ReverteranceGameInstance.h"

class UPlayerData* UReverteranceGameInstance::getPlayerData() {
	if (tutorial) {
		return tutorialdata;
	}

	return playerdata;
}

void UReverteranceGameInstance::setPlayerData(class UPlayerData* newPlayerData) {
	playerdata = newPlayerData;
}

void UReverteranceGameInstance::Init() {
	playerdata = NewObject<UPlayerData>();
}

void UReverteranceGameInstance::startTutorial() {
	tutorial = true;

	tutorialdata = NewObject<UPlayerData>();
	tutorialdata->initializeTutorialInventory();
}

void UReverteranceGameInstance::endTutorial() {
	tutorial = false;
}
