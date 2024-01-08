// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleWidgetBase.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Kismet/GameplayStatics.h"

void UTitleWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();

	// 위젯 이름으로 가져오기 다만, 우리가 찾는 것은 Button Class 이기에 형변환을 통해 가져옵니다.
	MakeRoomButton = Cast<UButton>(GetWidgetFromName(TEXT("MakeRoom_Button")));
	ConnectServerButton = Cast<UButton>(GetWidgetFromName(TEXT("ConnectServer_Button")));
	IPTextBox = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("ConnectServer_Button")));

	if (MakeRoomButton)
	{
		MakeRoomButton->OnClicked.AddDynamic(this, &UTitleWidgetBase::ProcessMakeRoom);
	}
	if (ConnectServerButton)
	{
		ConnectServerButton->OnClicked.AddDynamic(this, &UTitleWidgetBase::ProcessMakeRoom);
	}

}

void UTitleWidgetBase::ProcessMakeRoom()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("Lobby"), true, TEXT("listen"));
}

void UTitleWidgetBase::ProcessConnectServer()
{
	if (IPTextBox)
	{
		// 원래 시작 위치인 이곳에 if 문을 통해서 잘못된 값을 입력시 처리를 하는 코드를 추가해야 합니다.(if)
		// FName 은 검색을 빠르게 하기 위해서 글자를 숫자로 변환합니다. 다만 속도를 위해서 대소문자 구별을 하지 않는 것이 단점입니다.
		// 그래서 우리는 아래처럼 FName(*IPTextBox->GetText().ToString()) 번거로운 방식으로 가져와야 합니다.
		UGameplayStatics::OpenLevel(GetWorld(), FName(*IPTextBox->GetText().ToString()));
	}
}