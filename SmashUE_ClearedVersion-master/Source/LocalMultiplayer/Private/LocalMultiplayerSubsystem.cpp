// Fill out your copyright notice in the Description page of Project Settings.


#include "LocalMultiplayerSubsystem.h"
#include "Kismet/GameplayStatics.h"

void ULocalMultiplayerSubsystem::CreatAndInitializePlayers(ELocalMultiplayerInputMappingType MappingType)
{
	const ULocalMultiplayerSettings* LocalMultiplayerSettings = GetDefault<ULocalMultiplayerSettings>();

	for(int i = 0; i < (LocalMultiplayerSettings->GetNbKeyBoardProfiles() + LocalMultiplayerSettings->NbMaxGamepads); i++)
	{
		UGameplayStatics::CreatePlayer(GetWorld(), i);
	}
}

int ULocalMultiplayerSubsystem::GetAssignedPlayerIndexFromKeyboardProfileIndex(int KeyboardProfileIndex)
{
	if(PlayerIndexFromKeyboardProfileIndex.Contains(KeyboardProfileIndex))
	{
		return *PlayerIndexFromKeyboardProfileIndex.Find(KeyboardProfileIndex);
	}
	return -1;
}

int ULocalMultiplayerSubsystem::AssignPlayerToKeyboardProfile(int KeyboardProfileIndex)
{
	LastAssignPlayerIndex++;
	
	PlayerIndexFromKeyboardProfileIndex.Add(LastAssignPlayerIndex, KeyboardProfileIndex);

	return LastAssignPlayerIndex;
}

void ULocalMultiplayerSubsystem::AssignedKeyboardMapping(int PlayerIndex, int KeyboardProfileIndex,	ELocalMultiplayerInputMappingType MappingType) const
{
	ULocalPlayer* playerref = GetGameInstance()->GetLocalPlayerByIndex(PlayerIndex);
	
}

int ULocalMultiplayerSubsystem::GetAssignedPlayerIndexFromGamepadDeviceID(int DeviceID)
{
}

int ULocalMultiplayerSubsystem::AssignPlayerToGamepadDeviceID(int DeviceID)
{
}

void ULocalMultiplayerSubsystem::AssignGamepadInputMapping(int PlayerIndex,	ELocalMultiplayerInputMappingType MappingType) const
{
}
