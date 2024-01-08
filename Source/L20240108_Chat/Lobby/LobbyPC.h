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
};
