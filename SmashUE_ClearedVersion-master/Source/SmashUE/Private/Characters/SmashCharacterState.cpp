// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SmashCharacterState.h"
#include "Characters/SmashCharacterStateID.h"
#include "Characters/SmashCharacterStateMachine.h"


USmashCharacterState::USmashCharacterState()
{
	PrimaryComponentTick.bCanEverTick = false;
}

ESmashCharacterStateID USmashCharacterState::GetStateID()
{
	return ESmashCharacterStateID::None;
}

void USmashCharacterState::StateInit(USmashCharacterStateMachine* IntStateMachine)
{
	StateMachine = IntStateMachine;
	Character = IntStateMachine->GetCharacter();
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Magenta, FString::Printf(TEXT("Init State %d"), GetStateID()));
	
}

void USmashCharacterState::StateEnter(ESmashCharacterStateID PreviousStateID)
{
	
}

void USmashCharacterState::StateExit(ESmashCharacterStateID NextStateID)
{
	
}

void USmashCharacterState::StateTick(float DeltaTime)
{
	
}
