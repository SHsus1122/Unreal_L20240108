// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGM.h"

void ALobbyGM::PostLogin(APlayerController* NewPlayer)
{
	// Player Controller 숫자를 세어서 총 인원을 계산합니다. GameState 저장
	Super::PostLogin(NewPlayer);

	
}

void ALobbyGM::Logout(AController* Exiting)
{


	// 호출하면 Player State 를 날려버리기 때문에 이전과 다르게 그 전에 작업할 것들을 처리하고 부모를 호출합니다.
	Super::Logout(Exiting);
}
