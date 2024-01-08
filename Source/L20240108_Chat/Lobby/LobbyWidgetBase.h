// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LobbyWidgetBase.generated.h"

class UTextBlock;
class UScrollBox;
class UEditableTextBox;
/**
 * 
 */
UCLASS()
class L20240108_CHAT_API ULobbyWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	void UpdatePlayerCount(int32 InplayerCount);

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "UI")
	TObjectPtr<UTextBlock> PlayerCountText;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "UI")
	TObjectPtr<UScrollBox> ChatScrollBox;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "UI")
	TObjectPtr<UEditableTextBox> ChatInputTextBox;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "UI")
	TObjectPtr<UTextBlock> LeftTimeTextBox;
	
	UFUNCTION()
	void ProcessChanged(const FText& Text);
	
	UFUNCTION()
	void ProcessCommitted(const FText& Text, ETextCommit::Type CommitMethod);

	UFUNCTION(BlueprintCallable)
	void AddMessage(const FString& InMessage);

	void UpdateLeftTime(int InLeftTime);
};
