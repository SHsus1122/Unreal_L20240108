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
	}
}

void ALobbyGM::Logout(AController* Exiting)
{
	ALobbyGS* GS = GetGameState<ALobbyGS>();
	if (GS)
	{
		GS->DecreasePlayerCount();
	}

	// ȣ���ϸ� Player State �� ���������� ������ ������ �ٸ��� �� ���� �۾��� �͵��� ó���ϰ� �θ� ȣ���մϴ�.
	Super::Logout(Exiting);
}
