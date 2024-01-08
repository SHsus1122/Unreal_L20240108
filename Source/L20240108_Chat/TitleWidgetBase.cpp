// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleWidgetBase.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Kismet/GameplayStatics.h"

void UTitleWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();

	// ���� �̸����� �������� �ٸ�, �츮�� ã�� ���� Button Class �̱⿡ ����ȯ�� ���� �����ɴϴ�.
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
		// ���� ���� ��ġ�� �̰��� if ���� ���ؼ� �߸��� ���� �Է½� ó���� �ϴ� �ڵ带 �߰��ؾ� �մϴ�.(if)
		// FName �� �˻��� ������ �ϱ� ���ؼ� ���ڸ� ���ڷ� ��ȯ�մϴ�. �ٸ� �ӵ��� ���ؼ� ��ҹ��� ������ ���� �ʴ� ���� �����Դϴ�.
		// �׷��� �츮�� �Ʒ�ó�� FName(*IPTextBox->GetText().ToString()) ���ŷο� ������� �����;� �մϴ�.
		UGameplayStatics::OpenLevel(GetWorld(), FName(*IPTextBox->GetText().ToString()));
	}
}