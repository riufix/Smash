// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/SmashCharacter.h"
#include "GameFramework/GameModeBase.h"
#include "MatchGameMode.generated.h"

class ASmashCharacter;
class AArenaPlayerStart;

/**
 * 
 */
UCLASS()
class SMASHUE_API AMatchGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

protected:
	UPROPERTY()
	TArray<ASmashCharacter*> CharactersInsideArena;

private:
	void FindPlayerStartActorInArena(TArray<AArenaPlayerStart*>& ResultActors);

	void SpawnCharacters(const TArray<AArenaPlayerStart*>& SpawnPoints);
	
	TSubclassOf<ASmashCharacter> GetSmashCharacterClassForInputType(EAutoReceiveInput::Type InputeType) const;
};

