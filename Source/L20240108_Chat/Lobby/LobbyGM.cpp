// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGM.h"
#include "LobbyGS.h"

void ALobbyGM::PostLogin(APlayerController* NewPlayer)
{
	// Player Controller ���ڸ� ��� �� �ο��� ����մϴ�. GameState ����
	Super::PostLogin(NewPlayer);

	ALobbyGS* GS = GetGameState<ALobbyGS>();
	if (GS)
	{
		GS->IncreasePlayerCount();
		GS->OnRep_PlayerCount();	// Only Server Call
	}
}

void ALobbyGM::Logout(AController* Exiting)
{
	ALobbyGS* GS = GetGameState<ALobbyGS>();
	if (GS)
	{
		GS->DecreasePlayerCount();
		GS->OnRep_PlayerCount();	// Only Server Call
	}

	// ȣ���ϸ� Player State �� ���������� ������ ������ �ٸ��� �� ���� �۾��� �͵��� ó���ϰ� �θ� ȣ���մϴ�.
	Super::Logout(Exiting);
}

void ALobbyGM::BeginPlay()
{
	Super::BeginPlay();

	ALobbyGS* GS = GetGameState<ALobbyGS>();
	if (GS)
	{
		GS->OnRep_PlayerCount();	// Only Server Call
	}

	FTimerHandle LeftTimerHandle;
	// �� ���� ���� -1.0f �� ������ �ٷ� �����̰� ���ڰ� �̺��� ũ�� �� �� �ڿ� �����Ѵٴ� ��
	// [&] �� �ڱ� �ڽ��� ���� �����ͼ� ����Ѵٴ� �ǹ��Դϴ�.
	// �Ʒ� �ּ��� ���� �������� ���ٿ��� S2A_UpdateLeftTime �Լ� ȣ���� �Ұ����ϱ⿡ �Ʒ� �Լ��� ��������� ������ �մϴ�.
	//GetWorld()->GetTimerManager().SetTimer(LeftTimerHandle, 
	//	FTimerDelegate::CreateLambda(
	//		[&]() {
	//			if (GS)
	//			{
	//				GS->LeftTime--;
	//				//GS->S2A_UpdateLeftTime(GS->LeftTime); 
	//			}
	//		}
	//	), 
	//	1.0f, true, -1.0f);

	GetWorld()->GetTimerManager().SetTimer(LeftTimerHandle, this, &ALobbyGM::UpdateLeftTime, 1.0f, true, -1.0f);
}

void ALobbyGM::UpdateLeftTime()
{
	ALobbyGS* GS = GetGameState<ALobbyGS>();
	if (GS)
	{
		GS->LeftTime--;
		GS->S2A_UpdateLeftTime(GS->LeftTime);
	}
}
