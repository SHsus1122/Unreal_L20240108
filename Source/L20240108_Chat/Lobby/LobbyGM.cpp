// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGM.h"
#include "LobbyGS.h"

void ALobbyGM::PostLogin(APlayerController* NewPlayer)
{
	// Player Controller 숫자를 세어서 총 인원을 계산합니다. GameState 저장
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

	// 호출하면 Player State 를 날려버리기 때문에 이전과 다르게 그 전에 작업할 것들을 처리하고 부모를 호출합니다.
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
	// 맨 뒤의 인자 -1.0f 은 무조건 바로 시작이고 숫자가 이보다 크면 몇 초 뒤에 시작한다는 말
	// [&] 는 자기 자신의 것을 가져와서 사용한다는 의미입니다.
	// 아래 주석은 람다 사용법으로 람다에서 S2A_UpdateLeftTime 함수 호출은 불가능하기에 아래 함수를 사용하지는 말도록 합니다.
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
