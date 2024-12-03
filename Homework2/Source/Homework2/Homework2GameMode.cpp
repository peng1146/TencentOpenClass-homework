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

	// ���ⷽ����Ĭ��Ϊ5
	SpCubeNum = 5;

	// Ĭ�Ͻ���ʱ��60s
	TimeToEndGame = 60.0f;

	// �ܻ��ֳ�ʼΪ0
	TotalScore = 0;

	// �ؿ�����Ĭ��Ϊ"FirstPersonMap"
	CurrentLevelName = "FirstPersonMap"; 

}

void AHomework2GameMode::BeginPlay()
{
	Super::BeginPlay();  // ���ø����BeginPlay()

	// ���ø�����ɫ�ĺ����������ⷽ��
	ChangeColorOfCubes(SpCubeNum);

	// ���ü�ʱ������ TimeToEndGame ��������Ϸ
	GetWorld()->GetTimerManager().SetTimer(EndGameTimerHandle, this, &AHomework2GameMode::EndGame, TimeToEndGame, false);

	// ���� UMG ��ʾ�Ļ���
	// UpdateScoreboard();

}

void AHomework2GameMode::EndGame()
{
	// ��Ϸ�������߼�
	UE_LOG(LogTemplateGameMode, Log, TEXT("Game Over!"));

	// ��ȡ����Homework2Character���͵Ľ�ɫ
	TArray<AActor*> FoundCharacters;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AHomework2Character::StaticClass(), FoundCharacters);

	// ���������ҵ��Ľ�ɫ���ۼ�Score
	for (AActor* Actor : FoundCharacters)
	{
		AHomework2Character* Character = Cast<AHomework2Character>(Actor);
		if (Character)
		{
			// ʹ��GetScore()��ȡÿ����ɫ�ķ���
			TotalScore += Character->GetScore();
			// ������˷���
			UE_LOG(LogTemplateGameMode, Warning, TEXT("%s's Score: %d"), *Character->GetName(), Character->GetScore());

		}
	}

	// ����ܷ�
	UE_LOG(LogTemplateGameMode, Warning, TEXT("Total Score: %d"), TotalScore);

	// �ڴ˴����Դ���UI��ʾ������Ȳ���
	// ���磺��ʾ�ܻ��ֲ�������Ϸ

	// ������Ϸ���˳�
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);

}

void AHomework2GameMode::ChangeColorOfCubes(int32 N)
{
	// UE_LOG(LogTemplateGameMode, Log, TEXT("In ChangeColorOfRandomSMChamferCubes"));
	TArray<AActor*> AllActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AStaticMeshActor::StaticClass(), AllActors);

	TArray<AStaticMeshActor*> ChamferCubes;

	// ɸѡ���������Ƶ�����
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

	// ���������������������N�������ѡ������
	if (ChamferCubes.Num() <= N)
	{
		N = ChamferCubes.Num();
	}

	// ��ʼ����Ϊδѡ��
	TArray<bool> bIfChoose;
	for (int32 i = 0; i < ChamferCubes.Num(); ++i)
	{
		bIfChoose.Add(false);
	}

	// ������������
	UStaticMesh* NewStaticMesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, 
		TEXT("/Game/LevelPrototyping/Meshes/SM_ChamferCubeChange.SM_ChamferCubeChange")));
	if (!NewStaticMesh)
	{
		// UE_LOG(LogTemplateGameMode, Error, TEXT("Failed to load new static mesh!"));
		return;  // ����޷������������壬�˳�����
	}

	// ���ѡȡN�����岢�޸���ɫ
	for (int32 i = 0; i < N; ++i)
	{
		// UE_LOG(LogTemplateGameMode, Log, TEXT("In Choose Color"));
		AStaticMeshActor* SelectedActor = nullptr;
		while(1) 
		{
			// ���δѡ�����¼ѡ�е�Actor����������ѡ
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
			SelectedActor->GetStaticMeshComponent()->SetStaticMesh(NewStaticMesh);  // ������������
			
		}
	}
}