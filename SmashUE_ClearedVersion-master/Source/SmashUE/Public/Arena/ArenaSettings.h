// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/SmashCharacter.h"
#include "Engine/DeveloperSettings.h"
#include "ArenaSettings.generated.h"

/**
 * 
 */
UCLASS(Config = Game, defaultconfig, meta = (DisplayName = "Smash Arena Settings"))
class SMASHUE_API UArenaSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere,Category="Characters")
	TSubclassOf<ASmashCharacter> SmashCharacterClassP0;

	UPROPERTY(Config, EditAnywhere,Category="Characters")
	TSubclassOf<ASmashCharacter> SmashCharacterClassP1;

	UPROPERTY(Config, EditAnywhere,Category="Characters")
	TSubclassOf<ASmashCharacter> SmashCharacterClassP2;

	UPROPERTY(Config, EditAnywhere,Category="Characters")
	TSubclassOf<ASmashCharacter> SmashCharacterClassP3;
	
};
