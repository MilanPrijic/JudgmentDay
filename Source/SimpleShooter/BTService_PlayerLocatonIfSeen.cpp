// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocatonIfSeen.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/WidgetComponent.h"
#include "Kismet/GameplayStatics.h"


UBTService_PlayerLocatonIfSeen::UBTService_PlayerLocatonIfSeen()
{
	NodeName = TEXT("Update Player Location If Seen");
}

void UBTService_PlayerLocatonIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (PlayerPawn == nullptr) {
		return;
	}

	AAIController* AIController = OwnerComp.GetAIOwner();
	if (AIController == nullptr) {
		return;
	}

	if (AIController->LineOfSightTo(PlayerPawn))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);
	} else
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}
}

