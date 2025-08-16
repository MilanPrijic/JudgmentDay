// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"

#include "AIController.h"
#include "BTTask_ClearBlackboardValue.h"
#include "ShooterCharacter.h"

UBTTask_Shoot::UBTTask_Shoot()
{
	NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr) {
		return EBTNodeResult::Failed;
	}

	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	AShooterCharacter* ShooterCharacter = Cast<AShooterCharacter>(ControllingPawn);
	if (ShooterCharacter == nullptr) {
		return EBTNodeResult::Failed;
	}

	ShooterCharacter->Fire();

	return EBTNodeResult::Succeeded;
}