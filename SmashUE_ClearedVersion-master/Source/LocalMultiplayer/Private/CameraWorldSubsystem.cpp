// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraWorldSubsystem.h"

#include "Kismet/GameplayStatics.h"

void UCameraWorldSubsystem::PostInitialize()
{
	Super::PostInitialize();
}

void UCameraWorldSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);
	CameraMain = FindCameraByTag(TEXT("CameraMain"));
}

void UCameraWorldSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TickUpdateCameraPosition(DeltaTime);
}

void UCameraWorldSubsystem::AddFollowTarget(AActor* FollowTarget)
{
	FollowTargets.Add(FollowTarget);
}

void UCameraWorldSubsystem::RemoveFollowTarget(AActor* FollowTarget)
{
	FollowTargets.Remove(FollowTarget);
}

void UCameraWorldSubsystem::TickUpdateCameraPosition(float DeltaTime)
{
	FVector NewCameraPosition = CalculateAveragePositionBetweenTargets();
	NewCameraPosition.Y = CameraMain->GetComponentLocation().Y;
	CameraMain->SetWorldLocation(NewCameraPosition);
}

FVector UCameraWorldSubsystem::CalculateAveragePositionBetweenTargets()
{
	FVector TargetPosition;
	for (AActor* target : FollowTargets)
	{
		if(target != nullptr)
		{
			TargetPosition += target->GetActorLocation();
		}
	}
	return TargetPosition/FollowTargets.Num();
}

UCameraComponent* UCameraWorldSubsystem::FindCameraByTag(const FName& Tag) const
{
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), Tag, FollowTargets);
	return 
}
