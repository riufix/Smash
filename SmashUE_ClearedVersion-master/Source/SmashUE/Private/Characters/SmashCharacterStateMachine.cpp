// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SmashCharacterStateMachine.h"
#include "Characters/SmashCharacterStateID.h"
#include "Characters/SmashCharacterState.h"
#include "Characters/SmashCharacter.h"


ASmashCharacter* USmashCharacterStateMachine::GetCharacter() const
{
	return Character;
}

void USmashCharacterStateMachine::ChangeState(ESmashCharacterStateID NextStateID)
{
	USmashCharacterState* NextState = GetState(NextStateID);
	//si nexstate nest pas trouve ne rien faire
	if(NextState == nullptr) return;

	if(CurrentState != nullptr)
	{
		CurrentState->StateExit(NextStateID);
	}

	ESmashCharacterStateID PreviousStateID = CurrentStateID;
	CurrentStateID = NextStateID;
	CurrentState = NextState;

	if(CurrentState != nullptr)
	{
		CurrentState->StateEnter(NextStateID);
	}
	
}

USmashCharacterState* USmashCharacterStateMachine::GetState(ESmashCharacterStateID StateID) const
{
	for(USmashCharacterState* State : AllStates)
	{
		if(StateID == State->GetStateID())
			return State;
	}
	return nullptr;
}

void USmashCharacterStateMachine::Tick(float DeltaTime)
{
	if(CurrentState == nullptr) return;
	CurrentState->StateTick(DeltaTime);
}

void USmashCharacterStateMachine::Init(ASmashCharacter* InCharacter)
{
	Character = InCharacter;
	FindStates();
	InitStates();

	ChangeState(ESmashCharacterStateID::Idle);
}

void USmashCharacterStateMachine::FindStates()
{
	TArray<UActorComponent*> FoundComponents = Character->K2_GetComponentsByClass(USmashCharacterState::StaticClass());
	for(UActorComponent* StateComponent : FoundComponents)
	{
		USmashCharacterState* State = Cast<USmashCharacterState>(StateComponent);
		if(State == nullptr) continue;
		if(State->GetStateID() == ESmashCharacterStateID::None) continue;

		AllStates.Add(State);
	}
}

void USmashCharacterStateMachine::InitStates()
{
	for(USmashCharacterState* State : AllStates)
	{
		State->StateInit(this);
	}
}
