// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPC.h"
#include "LobbyWidgetBase.h"

void ALobbyPC::BeginPlay()
{
	Super::BeginPlay();

	// 하드 코딩으로 블루프린트의 위젯 가져오는 방법(잘 사용 X)
	FSoftClassPath LobbyWidgetClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/Lobby/WBP_Lobby.WBP_Lobby_C'"));
	UClass* WidgetClass = LobbyWidgetClass.TryLoadClass<UUserWidget>();

	// 플레이어 본인의 것에서만 위젯을 생성시키기 위해서
	if (WidgetClass && IsLocalPlayerController())
	{
		//CreateWidget<UUserWidget>(this, WidgetClass);
		LobbyWidgetObject = CreateWidget<ULobbyWidgetBase>(this, WidgetClass);
		if (LobbyWidgetObject)
		{
			LobbyWidgetObject->AddToViewport();

			// 화면에 안 나오게 하는 함수
			//LobbyWidgetObject->RemoveFromViewport();
		}
	}
}
