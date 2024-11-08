// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SmashCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "CameraWorldSubsystem.h"
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

	GetWorld()->GetSubsystem<UCameraWorldSubsystem>()->AddFollowTarget(this);
	
}

// Called every frame
void ASmashCharacter::Tick(float DeltaTime)	
{
	Super::Tick(DeltaTime);
	TickStateMachine(DeltaTime);
	RotateMeshUsingOrientX();

}

// Called to bind functionality to input
void ASmashCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	SetupMappingContextIntoController();
	RotateMeshUsingOrientX();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInputComponent == nullptr) return;
	BindInputMoveXAxisAndActions(EnhancedInputComponent);
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

void ASmashCharacter::TickStateMachine(float DeltaTime) const
{
	if(StateMachine == nullptr) return;
	StateMachine->Tick(DeltaTime);
}

void ASmashCharacter::SetupMappingContextIntoController() const
{
	APlayerController* PlayerController = Cast<APlayerController>(Controller);
	if(PlayerController == nullptr) return;
	ULocalPlayer* Player = PlayerController->GetLocalPlayer();
	if(Player == nullptr) return;
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = Player->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if(InputSubsystem == nullptr) return;
	
	InputSubsystem->AddMappingContext(InputMappingContext, 0);
}

float ASmashCharacter::GetInputMoveX() const
{
	return InputMoveX;
}

void ASmashCharacter::OnInputMoveXFast(const FInputActionValue& InputActionValue)
{
	InputMoveX = InputActionValue.Get<float>();
	InputMoveXFastEvent.Broadcast(InputMoveX);
}

void ASmashCharacter::BindInputMoveXAxisAndActions(UEnhancedInputComponent* EnhanceInputComponent)
{
	if(InputData == nullptr) return;

	if(InputData->InputActionMoveX)
	{
		EnhanceInputComponent->BindAction(InputData->InputActionMoveX, ETriggerEvent::Started, this, &ASmashCharacter::OnInputMoveX);
		EnhanceInputComponent->BindAction(InputData->InputActionMoveX, ETriggerEvent::Completed, this, &ASmashCharacter::OnInputMoveX);
		EnhanceInputComponent->BindAction(InputData->InputActionMoveX, ETriggerEvent::Triggered, this, &ASmashCharacter::OnInputMoveX);
	}
	if(InputData->InputActionMoveXFast)
	{
		EnhanceInputComponent->BindAction(InputData->InputActionMoveXFast, ETriggerEvent::Triggered, this, &ASmashCharacter::OnInputMoveXFast);
	}
}

void ASmashCharacter::OnInputMoveX(const FInputActionValue& InputActionValue)
{
	InputMoveX = InputActionValue.Get<float>();
}
