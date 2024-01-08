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
	// 게임 모드도 이미 기본적으로 가지고 있지만, 우리는 연습을 위해서...
	// Player 인원수를 카운트해서 담을 변수를 만들어줍니다.
	UPROPERTY(ReplicatedUsing = "OnRep_PlayerCount", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int32 PlayerCount;

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;


public:
	UFUNCTION()
	void OnRep_PlayerCount();
	
	// Server 에서 모두에게 호출
	UFUNCTION(NetMulticast, Unreliable)
	void S2A_UpdateLeftTime(int InLeftTime);	// Call Server
	void S2A_UpdateLeftTime_Implementation(int InLeftTime);	// Execute All Clients

	// 플레이 타임 남은 시간을 담을 변수, C++ 은 헤더에서 바로 초기화 가능(UPROPERTY 사용하지 않았을 때만)
	int32 LeftTime = 60;
};
