// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "Engine/DeveloperSettings.h"
#include "LocalMultiplayerSettings.generated.h"

/**
 * 
 */

UENUM()
enum class ELocalMultiplayerInputMappingType
{
	InGame,
	Menu
};

USTRUCT()
struct FLocalMultiplayerProfileData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FName ProfileName;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputMappingContext>IMCIngame;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputMappingContext>IMCMenu;

	bool ContainsKey(const FKey& key, ELocalMultiplayerInputMappingType MappingType) const;

	UInputMappingContext* GetIMCFromType(ELocalMultiplayerInputMappingType MappingType) const;
};

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName = "Local Multiplayer Settings"))
class LOCALMULTIPLAYER_API ULocalMultiplayerSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Config, EditAnywhere, Category = "LocalMultiplayer")
	TArray<FLocalMultiplayerProfileData> KeyboardProfileDatas;

	int GetNbKeyBoardProfiles()const;
	int FindKeyBoardProfileIndexFromKey(const FKey& Key, ELocalMultiplayerInputMappingType MappingType)const;

	UPROPERTY(Config, EditAnywhere, Category = "LocalMultiplayer")
	FLocalMultiplayerProfileData GamePadProfileData;

	UPROPERTY(Config, EditAnywhere, Category = "LocalMultiplayer")
	int NbMaxGamepads = 4;
};
