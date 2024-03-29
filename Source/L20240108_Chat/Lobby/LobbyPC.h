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

	// 하드 코딩으로 사용할 때
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UI")
	TObjectPtr<ULobbyWidgetBase> LobbyWidgetObject;

	// 블루프린트에서 편집에서 사용할 때
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UI")
	//TObjectPtr<ULobbyWidgetBase> LobbyWidgetClass;

	// WithValidation 서버에서 검증하는 절차를 추가, 클라이언트에서 호출
	UFUNCTION(Server, Unreliable, WithValidation)
	void C2S_SendMessage(const FString& InMessage);	// Client Call
	bool C2S_SendMessage_Validate(const FString& InMessage);
	void C2S_SendMessage_Implementation(const FString& InMessage);

	// 서버에서 클라이언트 호출
	UFUNCTION(Client, Reliable)
	void S2C_SendMessage(const FString& InMessage);	// Server Call
	void S2C_SendMessage_Implementation(const FString& InMessage);
};
