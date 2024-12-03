// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Logging/LogMacros.h"
#include "Blueprint/UserWidget.h"
#include "Homework2GameMode.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateGameMode, Log, All);

UCLASS(minimalapi)
class AHomework2GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AHomework2GameMode();

protected:
	// ��дBeginPlay����
	virtual void BeginPlay() override;

	// ʱ���ʱ�����
	FTimerHandle EndGameTimerHandle;

	// ��Ϸ��������ʱ��ʱ�䣨�����ڱ༭�������ã�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Settings")
	float TimeToEndGame;

	// ����������������ֵܷı���
	int32 TotalScore;

	// ��ǰ�ؿ����ƣ������ڱ༭�������ã�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Settings")
	FString CurrentLevelName;

	// ������ʾ��һ��ֺ��ܻ��ֵ� UMG �ؼ�
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	class UUserWidget* ScoreboardWidget;*/

	// ������Ϸ
	void EndGame();

	// ���� UMG UI
	// void UpdateScoreboard();

private:
	// ���ڸ�����ɫ�ĺ���
	void ChangeColorOfCubes(int32 N);
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	int32 SpCubeNum; // ���ⷽ����������޸�

};



