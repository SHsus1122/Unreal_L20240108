// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LobbyPC.generated.h"

class ULobbyWidgetBase;
/**
 * 
 */
UCLASS()
class L20240108_CHAT_API ALobbyPC : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	// �ϵ� �ڵ����� ����� ��
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UI")
	TObjectPtr<ULobbyWidgetBase> LobbyWidgetObject;

	// �������Ʈ���� �������� ����� ��
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UI")
	//TObjectPtr<ULobbyWidgetBase> LobbyWidgetClass;

	// WithValidation �������� �����ϴ� ������ �߰�, Ŭ���̾�Ʈ���� ȣ��
	UFUNCTION(Server, Unreliable, WithValidation)
	void C2S_SendMessage(const FString& InMessage);	// Client Call
	bool C2S_SendMessage_Validate(const FString& InMessage);
	void C2S_SendMessage_Implementation(const FString& InMessage);

	// �������� Ŭ���̾�Ʈ ȣ��
	UFUNCTION(Client, Reliable)
	void S2C_SendMessage(const FString& InMessage);	// Server Call
	void S2C_SendMessage_Implementation(const FString& InMessage);
};
