// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPC.h"
#include "LobbyWidgetBase.h"

void ALobbyPC::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeUIOnly());
	bShowMouseCursor = true;

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

bool ALobbyPC::C2S_SendMessage_Validate(const FString& InMessage)
{
	return true;
}

void ALobbyPC::C2S_SendMessage_Implementation(const FString& InMessage)
{
	// �ݺ����� ���ؼ� ��� �÷��̾� ��Ʈ�ѷ��� �����ɴϴ�.
	for (auto It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		// It->Get(); �� (*It) �� �ϴ°Ͱ� �����ϴ�.
		ALobbyPC* PC = Cast<ALobbyPC>(*It);
		if (PC)
		{
			PC->S2C_SendMessage(InMessage);
		}
	}
}

// Execute Client
// ȣ���� �������� ������ ������ Ŭ���̾�Ʈ���� �����ϰ� �մϴ�.
void ALobbyPC::S2C_SendMessage_Implementation(const FString& InMessage)
{
	if (LobbyWidgetObject)
	{
		LobbyWidgetObject->AddMessage(InMessage);
	}
}
