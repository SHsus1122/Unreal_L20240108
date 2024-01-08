// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGS.h"
#include "Net/UnrealNetwork.h"
#include "LobbyPC.h"
#include "Kismet/GameplayStatics.h"
#include "LobbyWidgetBase.h"

void ALobbyGS::IncreasePlayerCount()
{
	PlayerCount++;
	UE_LOG(LogTemp, Warning, TEXT("PlayerCount %d"), PlayerCount);
}

void ALobbyGS::DecreasePlayerCount()
{
	PlayerCount--;
	UE_LOG(LogTemp, Warning, TEXT("PlayerCount %d"), PlayerCount);
}

// Server 빼고 실행
void ALobbyGS::OnRep_PlayerCount()
{
	ALobbyPC* PC = Cast<ALobbyPC>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	// BeginPlay 이후 위젯을 생성하는데 그 전에 호출되서 터지는 것을 방지하기 위해서 PC->LobbyWidgetObject 를 if 문에 추가
	if (PC && PC->LobbyWidgetObject)
	{
		// UI Update
		PC->LobbyWidgetObject->UpdatePlayerCount(PlayerCount);
	}
}

void ALobbyGS::S2A_UpdateLeftTime_Implementation(int InLeftTime)
{
	LeftTime = InLeftTime;

	ALobbyPC* PC = Cast<ALobbyPC>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	// BeginPlay 이후 위젯을 생성하는데 그 전에 호출되서 터지는 것을 방지하기 위해서 PC->LobbyWidgetObject 를 if 문에 추가
	if (PC && PC->LobbyWidgetObject)
	{
		// UI Update
		PC->LobbyWidgetObject->UpdateLeftTime(LeftTime);
	}
}

void ALobbyGS::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ALobbyGS, PlayerCount);

	// 특정 조건에 따라 리플리케이트를 보내는 매크로
	//DOREPLIFETIME_CONDITION(ALobbyGS, PlayerCount, COND_InitialOnly);
}
