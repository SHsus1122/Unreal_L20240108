// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPC.h"
#include "LobbyWidgetBase.h"

void ALobbyPC::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeUIOnly());
	bShowMouseCursor = true;

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

bool ALobbyPC::C2S_SendMessage_Validate(const FString& InMessage)
{
	return true;
}

void ALobbyPC::C2S_SendMessage_Implementation(const FString& InMessage)
{
	// 반복문을 통해서 모든 플레이어 컨트롤러를 가져옵니다.
	for (auto It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		// It->Get(); 는 (*It) 를 하는것과 같습니다.
		ALobbyPC* PC = Cast<ALobbyPC>(*It);
		if (PC)
		{
			PC->S2C_SendMessage(InMessage);
		}
	}
}

// Execute Client
// 호출은 서버에서 하지만 동작은 클라이언트에서 동작하게 합니다.
void ALobbyPC::S2C_SendMessage_Implementation(const FString& InMessage)
{
	if (LobbyWidgetObject)
	{
		LobbyWidgetObject->AddMessage(InMessage);
	}
}
