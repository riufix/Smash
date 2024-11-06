﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputTriggers.h"
#include "InputTriggerDoubleTap.generated.h"

/**
 * 
 */
UCLASS(NotBlueprintable, meta = (DisplayName= "Double Tap", NotInputConfigurable="true"))
class SMASHUE_API UInputTriggerDoubleTap : public UInputTrigger
{
	GENERATED_BODY()

protected:
	virtual ETriggerState UpdateState_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue ModifiedValue, float DeltaTime) override;

public:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Trigger Settings", meta=(DisplayThumbnail="false"))
	float Delay = 0.5f;

private:
	float LastTappedTime = 0.f;
};
