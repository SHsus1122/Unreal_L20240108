// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyWidgetBase.h"
#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"
#include "Components/EditableTextBox.h"

void ULobbyWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();

	PlayerCountText = Cast<UTextBlock>(GetWidgetFromName("PlayerCount_Text"));
	ChatScrollBox = Cast<UScrollBox>(GetWidgetFromName("Chat_ScrollBox"));
	ChatInputTextBox = Cast<UEditableTextBox>(GetWidgetFromName("ChatInput_TextBox"));
}

void ULobbyWidgetBase::UpdatePlayerCount(int32 InplayerCount)
{
	// 혹시나 null 으로 인해서 엔진 꺼지는 것을 방지하기 위해서
	if (PlayerCountText)
	{
		FString Message = FString::Printf(TEXT("%d 명"), InplayerCount);
		PlayerCountText->SetText(FText::FromString(Message));
	}
}
