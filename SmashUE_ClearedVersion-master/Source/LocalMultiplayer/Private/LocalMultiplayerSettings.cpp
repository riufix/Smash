// Fill out your copyright notice in the Description page of Project Settings.


#include "LocalMultiplayerSettings.h"

#include "InputMappingContext.h"

bool FLocalMultiplayerProfileData::ContainsKey(const FKey& Key, ELocalMultiplayerInputMappingType MappingType) const
{
	UInputMappingContext* CurrentIMC = GetIMCFromType(MappingType);
	if(CurrentIMC == nullptr) return false;

	TArray<FEnhancedActionKeyMapping> MappingList = CurrentIMC->GetMappings();
	for(FEnhancedActionKeyMapping Mapping : MappingList)
	{
		if(Mapping.Key == Key)
		{
			return true;
		}
	}
	return false;
}

UInputMappingContext* FLocalMultiplayerProfileData::GetIMCFromType(ELocalMultiplayerInputMappingType MappingType) const
{
	switch (MappingType)
	{
	case ELocalMultiplayerInputMappingType::InGame:
		return IMCIngame;
	case ELocalMultiplayerInputMappingType::Menu:
		return IMCMenu;
	default:
		return nullptr;
	}
}

int ULocalMultiplayerSettings::GetNbKeyBoardProfiles() const
{
	return KeyboardProfileDatas.Num();
}

int ULocalMultiplayerSettings::FindKeyBoardProfileIndexFromKey(const FKey& Key,	ELocalMultiplayerInputMappingType MappingType) const
{
	for(int i = 0; i < KeyboardProfileDatas.Num(); i++)
	{
		if(KeyboardProfileDatas[i].ContainsKey(Key, MappingType))
		{
			return i;
		}
	}
	return -1;
}
