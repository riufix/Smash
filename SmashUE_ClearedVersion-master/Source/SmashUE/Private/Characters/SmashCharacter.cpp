// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SmashCharacter.h"

#include "Characters/SmashCharacterStateMachine.h"

 //Sets default values

 //Called when the game starts or when spawned


ASmashCharacter::ASmashCharacter()
{
	//Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASmashCharacter::BeginPlay()
{
	Super::BeginPlay();
	CreateStateMachine();

	InitStateMachine();
	
}

// Called every frame
void ASmashCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
 	RotateMeshUsingOrientX();

}

// Called to bind functionality to input
void ASmashCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	RotateMeshUsingOrientX();
}

float ASmashCharacter::GetOrientX() const
{
	return OrientX;
}

void ASmashCharacter::SetOrientX(float NewOrientX)
{
	OrientX = NewOrientX;
}

void ASmashCharacter::RotateMeshUsingOrientX() const
{
	FRotator Rotation = GetMesh()->GetRelativeRotation();
	Rotation.Yaw = -90.f * OrientX;
	GetMesh()->SetRelativeRotation(Rotation);
}

void ASmashCharacter::CreateStateMachine()
{
	StateMachine = NewObject<USmashCharacterStateMachine>(this);
}

void ASmashCharacter::InitStateMachine()
{
	if(StateMachine == nullptr) return;
	StateMachine->Init(this);
}
