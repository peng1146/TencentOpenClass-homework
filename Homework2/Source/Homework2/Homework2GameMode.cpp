// Copyright Epic Games, Inc. All Rights Reserved.

#include "Homework2GameMode.h"
#include "Homework2Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/StaticMeshActor.h"
#include "Materials/MaterialInstanceDynamic.h"

DEFINE_LOG_CATEGORY(LogTemplateGameMode);

AHomework2GameMode::AHomework2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// 特殊方块数默认为5
	SpCubeNum = 5;

	// 默认结束时间60s
	TimeToEndGame = 60.0f;

	// 总积分初始为0
	TotalScore = 0;

	// 关卡名称默认为"FirstPersonMap"
	CurrentLevelName = "FirstPersonMap"; 

}

void AHomework2GameMode::BeginPlay()
{
	Super::BeginPlay();  // 调用父类的BeginPlay()

	// 调用更改颜色的函数设置特殊方块
	ChangeColorOfCubes(SpCubeNum);

	// 设置计时器，在 TimeToEndGame 秒后结束游戏
	GetWorld()->GetTimerManager().SetTimer(EndGameTimerHandle, this, &AHomework2GameMode::EndGame, TimeToEndGame, false);

	// 更新 UMG 显示的积分
	// UpdateScoreboard();

}

void AHomework2GameMode::EndGame()
{
	// 游戏结束的逻辑
	UE_LOG(LogTemplateGameMode, Log, TEXT("Game Over!"));

	// 获取所有Homework2Character类型的角色
	TArray<AActor*> FoundCharacters;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AHomework2Character::StaticClass(), FoundCharacters);

	// 遍历所有找到的角色，累加Score
	for (AActor* Actor : FoundCharacters)
	{
		AHomework2Character* Character = Cast<AHomework2Character>(Actor);
		if (Character)
		{
			// 使用GetScore()获取每个角色的分数
			TotalScore += Character->GetScore();
			// 输出个人分数
			UE_LOG(LogTemplateGameMode, Warning, TEXT("%s's Score: %d"), *Character->GetName(), Character->GetScore());

		}
	}

	// 输出总分
	UE_LOG(LogTemplateGameMode, Warning, TEXT("Total Score: %d"), TotalScore);

	// 在此处可以触发UI提示、结算等操作
	// 例如：显示总积分并结束游戏

	// 结束游戏并退出
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);

}

void AHomework2GameMode::ChangeColorOfCubes(int32 N)
{
	// UE_LOG(LogTemplateGameMode, Log, TEXT("In ChangeColorOfRandomSMChamferCubes"));
	TArray<AActor*> AllActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AStaticMeshActor::StaticClass(), AllActors);

	TArray<AStaticMeshActor*> ChamferCubes;

	// 筛选出符合名称的物体
	for (AActor* Actor : AllActors)
	{
		// UE_LOG(LogTemplateGameMode, Log, TEXT("In Select"));
		AStaticMeshActor* StaticMeshActor = Cast<AStaticMeshActor>(Actor);
		if (StaticMeshActor && StaticMeshActor->GetStaticMeshComponent())
		{
			if (StaticMeshActor->GetStaticMeshComponent()->GetStaticMesh()->GetName() == TEXT("SM_ChamferCube"))
			{
				ChamferCubes.Add(StaticMeshActor);
			}
		}
	}

	// 如果符合条件的物体少于N个，随机选择所有
	if (ChamferCubes.Num() <= N)
	{
		N = ChamferCubes.Num();
	}

	// 初始化均为未选中
	TArray<bool> bIfChoose;
	for (int32 i = 0; i < ChamferCubes.Num(); ++i)
	{
		bIfChoose.Add(false);
	}

	// 加载新网格体
	UStaticMesh* NewStaticMesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, 
		TEXT("/Game/LevelPrototyping/Meshes/SM_ChamferCubeChange.SM_ChamferCubeChange")));
	if (!NewStaticMesh)
	{
		// UE_LOG(LogTemplateGameMode, Error, TEXT("Failed to load new static mesh!"));
		return;  // 如果无法加载新网格体，退出函数
	}

	// 随机选取N个物体并修改颜色
	for (int32 i = 0; i < N; ++i)
	{
		// UE_LOG(LogTemplateGameMode, Log, TEXT("In Choose Color"));
		AStaticMeshActor* SelectedActor = nullptr;
		while(1) 
		{
			// 如果未选过则记录选中的Actor，否则重新选
			int32 RandomIndex = FMath::RandRange(0, ChamferCubes.Num() - 1);
			if (!bIfChoose[RandomIndex]) {
				SelectedActor = ChamferCubes[RandomIndex];
				bIfChoose[RandomIndex] = true;
				break;
			}
		}
		
		if (SelectedActor != nullptr)
		{
			// UE_LOG(LogTemplateGameMode, Log, TEXT("In Change StaticMesh"));
			SelectedActor->GetStaticMeshComponent()->SetStaticMesh(NewStaticMesh);  // 设置新网格体
			
		}
	}
}