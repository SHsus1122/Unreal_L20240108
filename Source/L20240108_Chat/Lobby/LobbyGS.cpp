// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGS.h"
#include "Net/UnrealNetwork.h"

void ALobbyGS::IncreasePlayerCount()
{
	PlayerCount++;
}

void ALobbyGS::DecreasePlayerCount()
{
	PlayerCount--;
}

void ALobbyGS::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ALobbyGS, PlayerCount);

	// Ư�� ���ǿ� ���� ���ø�����Ʈ�� ������ ��ũ��
	//DOREPLIFETIME_CONDITION()
}
