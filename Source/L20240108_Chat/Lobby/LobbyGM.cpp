// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGM.h"

void ALobbyGM::PostLogin(APlayerController* NewPlayer)
{
	// Player Controller ���ڸ� ��� �� �ο��� ����մϴ�. GameState ����
	Super::PostLogin(NewPlayer);

	
}

void ALobbyGM::Logout(AController* Exiting)
{


	// ȣ���ϸ� Player State �� ���������� ������ ������ �ٸ��� �� ���� �۾��� �͵��� ó���ϰ� �θ� ȣ���մϴ�.
	Super::Logout(Exiting);
}
