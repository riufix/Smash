// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/States/SmashCharacterStateIdle.h"

#include "Characters/SmashCharacter.h"
#include "Characters/SmashCharacterSettings.h"
#include "Characters/SmashCharacterStateMachine.h"


ESmashCharacterStateID USmashCharacterStateIdle::GetStateID()
{
	return ESmashCharacterStateID::Idle;
}

void USmashCharacterStateIdle::OnInputMoveXFast(float InputMoveX)
{
	StateMachine->ChangeState(ESmashCharacterStateID::Run);
}

void USmashCharacterStateIdle::StateEnter(ESmashCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	GEngine->AddOnScreenDebugMessage(-1, 3.f,FColor::Cyan,TEXT("Enter StateIdle"));
	Character->InputMoveXFastEvent.AddDynamic(this, &USmashCharacterStateIdle::OnInputMoveXFast);
}

void USmashCharacterStateIdle::StateExit(ESmashCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);	
	GEngine->AddOnScreenDebugMessage(-1, 3.f,FColor::Red,TEXT("Exit StateIdle"));
	Character->InputMoveXFastEvent.RemoveDynamic(this, &USmashCharacterStateIdle::OnInputMoveXFast);


}

void USmashCharacterStateIdle::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
	
	const USmashCharacterSettings* SmasCharacterSettings = GetDefault<USmashCharacterSettings>();	
	GEngine-> AddOnScreenDebugMessage(-1, 3.f,FColor::Green,TEXT("Tick StateIdle"));

	if(FMath::Abs(Character->GetInputMoveX()) > SmasCharacterSettings->InputMoveXTreshold)
	{
		StateMachine->ChangeState(ESmashCharacterStateID::Walk);
	}
	
}


