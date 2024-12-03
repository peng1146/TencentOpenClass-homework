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
	// 重写BeginPlay方法
	virtual void BeginPlay() override;

	// 时间计时器句柄
	FTimerHandle EndGameTimerHandle;

	// 游戏结束倒计时的时间（可以在编辑器中设置）
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Settings")
	float TimeToEndGame;

	// 声明保存所有玩家总分的变量
	int32 TotalScore;

	// 当前关卡名称（可以在编辑器中设置）
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Settings")
	FString CurrentLevelName;

	// 用于显示玩家积分和总积分的 UMG 控件
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	class UUserWidget* ScoreboardWidget;*/

	// 结束游戏
	void EndGame();

	// 更新 UMG UI
	// void UpdateScoreboard();

private:
	// 用于更改颜色的函数
	void ChangeColorOfCubes(int32 N);
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	int32 SpCubeNum; // 特殊方块个数，可修改

};



