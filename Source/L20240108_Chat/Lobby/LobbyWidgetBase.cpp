// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyWidgetBase.h"
#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"
#include "Components/EditableTextBox.h"
#include "LobbyPC.h"

void ULobbyWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();

	PlayerCountText = Cast<UTextBlock>(GetWidgetFromName("PlayerCount_Text"));
	ChatScrollBox = Cast<UScrollBox>(GetWidgetFromName("Chat_ScrollBox"));
	ChatInputTextBox = Cast<UEditableTextBox>(GetWidgetFromName("ChatInput_TextBox"));

	if (ChatInputTextBox)
	{
		ChatInputTextBox->OnTextChanged.AddDynamic(this, &ULobbyWidgetBase::ProcessChanged);
		ChatInputTextBox->OnTextCommitted.AddDynamic(this, &ULobbyWidgetBase::ProcessCommitted);
	}

	LeftTimeTextBox = Cast<UTextBlock>(GetWidgetFromName("LeftTimeTextBox"));
}

void ULobbyWidgetBase::ProcessChanged(const FText& Text)
{

}

void ULobbyWidgetBase::ProcessCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{
	ALobbyPC* PC = Cast<ALobbyPC>(GetOwningPlayer());

	// 위젯은 PlayerController 가 가지고 있습니다. 이를 알고 작업을 이어가야 합니다.
	if (PC)
	{
		switch (CommitMethod)
		{
		case ETextCommit::OnEnter:
			PC->C2S_SendMessage(ChatInputTextBox->GetText().ToString());
			// 엔터 이후에 초기화 시켜주는 함수 이를 해줘야 이전 채팅에서 이어치는 문제가 해결 됩니다.
			ChatInputTextBox->SetText(FText::FromString(TEXT("")));
			break;
		case ETextCommit::OnCleared:
			// 위젯은 PlayerController 가 가지고 있기 때문에 채팅이 끝나면 아래처럼 마우서커서 지우기
			ChatInputTextBox->SetUserFocus(PC);
			break;
		}
	}
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

void ULobbyWidgetBase::AddMessage(const FString& InMessage)
{
	// 만약 ChatScrollBox 가
	if (ChatScrollBox)
	{
		// NewMessage 를 가지고 있는 녀석은 ChatScrollBox 입니다. 이를 만들 때 지정도 해줍니다.
		UTextBlock* NewMessage = NewObject<UTextBlock>(ChatScrollBox);
		if (NewMessage)
		{

			NewMessage->SetText(FText::FromString(InMessage));
			// SetFont(FSlateFontInfo); 이렇게 바로 만들면 초기값을 모두 날리고 가져오게 됩니다.
			// 그래서 아래처럼 원래 있던 폰트의 디폴트 정보를 가져온다음 변경해서 사용합니다.
			FSlateFontInfo NewFont = NewMessage->GetFont();
			NewFont.Size = 18;
			NewMessage->SetFont(NewFont);
			ChatScrollBox->AddChild(NewMessage);
			ChatScrollBox->ScrollToEnd();
		}
	}
}

void ULobbyWidgetBase::UpdateLeftTime(int InLeftTime)
{
	if (LeftTimeTextBox)
	{
		if (InLeftTime > 0) 
		{
			FString Message = FString::Printf(TEXT("%d초 남음"), InLeftTime);
			LeftTimeTextBox->SetText(FText::FromString(Message));
		}
		else
		{
			LeftTimeTextBox->SetText(FText::FromString(TEXT("시작")));
		}
	}
}
