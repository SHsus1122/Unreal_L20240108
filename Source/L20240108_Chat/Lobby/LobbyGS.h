// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "LobbyGS.generated.h"

/**
 * 
 */
UCLASS()
class L20240108_CHAT_API ALobbyGS : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void IncreasePlayerCount();

	UFUNCTION(BlueprintCallable)
	void DecreasePlayerCount();

protected:
	// ���� ��嵵 �̹� �⺻������ ������ ������, �츮�� ������ ���ؼ�...
	// Player �ο����� ī��Ʈ�ؼ� ���� ������ ������ݴϴ�.
	UPROPERTY(Replicated)
	int32 PlayerCount;

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;
};