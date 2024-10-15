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
	for(int i = 0; i < )
	return -1;
}

int ULocalMultiplayerSubsystem::AssignPlayerToKeyboardProfile(int KeyboardProfileIndex)
{
}

void ULocalMultiplayerSubsystem::AssignedKeyboardMapping(int PlayerIndex, int KeyboardProfileIndex,	ELocalMultiplayerInputMappingType MappingType) const
{
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
