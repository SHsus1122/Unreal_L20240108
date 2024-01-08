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
};
