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
	UPROPERTY(ReplicatedUsing = "OnRep_PlayerCount", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int32 PlayerCount;

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;


public:
	UFUNCTION()
	void OnRep_PlayerCount();
	
	// Server ���� ��ο��� ȣ��
	UFUNCTION(NetMulticast, Unreliable)
	void S2A_UpdateLeftTime(int InLeftTime);	// Call Server
	void S2A_UpdateLeftTime_Implementation(int InLeftTime);	// Execute All Clients

	// �÷��� Ÿ�� ���� �ð��� ���� ����, C++ �� ������� �ٷ� �ʱ�ȭ ����(UPROPERTY ������� �ʾ��� ����)
	int32 LeftTime = 60;
};
