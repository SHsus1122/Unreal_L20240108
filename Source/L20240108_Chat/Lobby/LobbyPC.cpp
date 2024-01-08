// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPC.h"
#include "LobbyWidgetBase.h"

void ALobbyPC::BeginPlay()
{
	Super::BeginPlay();

	// �ϵ� �ڵ����� �������Ʈ�� ���� �������� ���(�� ��� X)
	FSoftClassPath LobbyWidgetClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/Lobby/WBP_Lobby.WBP_Lobby_C'"));
	UClass* WidgetClass = LobbyWidgetClass.TryLoadClass<UUserWidget>();

	// �÷��̾� ������ �Ϳ����� ������ ������Ű�� ���ؼ�
	if (WidgetClass && IsLocalPlayerController())
	{
		//CreateWidget<UUserWidget>(this, WidgetClass);
		LobbyWidgetObject = CreateWidget<ULobbyWidgetBase>(this, WidgetClass);
		if (LobbyWidgetObject)
		{
			LobbyWidgetObject->AddToViewport();

			// ȭ�鿡 �� ������ �ϴ� �Լ�
			//LobbyWidgetObject->RemoveFromViewport();
		}
	}
}
