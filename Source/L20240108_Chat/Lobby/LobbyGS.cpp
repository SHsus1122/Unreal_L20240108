// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGS.h"
#include "Net/UnrealNetwork.h"

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

void ALobbyGS::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ALobbyGS, PlayerCount);

	// 특정 조건에 따라 리플리케이트를 보내는 매크로
	//DOREPLIFETIME_CONDITION()
}
