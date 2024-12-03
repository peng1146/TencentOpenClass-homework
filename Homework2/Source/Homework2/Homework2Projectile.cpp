// Copyright Epic Games, Inc. All Rights Reserved.

#include "Homework2Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Homework2Character.h"
#include "Engine/StaticMeshActor.h"

DEFINE_LOG_CATEGORY(LogTemplateProjectile);

AHomework2Projectile::AHomework2Projectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AHomework2Projectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;

	// Ĭ�ϻ���ֵ
	ScoreAmount = 10;

	// ��С��Ĭ�ϱ���
	SmallTimes = 1;

	// ��ҪĿ������Ĭ�ϱ���
	Times = 2;

}

void AHomework2Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		// FiringCharacter = Cast<AHomework2Character>(GetOwner());
		// UE_LOG(LogTemp, Log, TEXT("Character Name: %s"), *FiringCharacter->GetName());
		// ����Character�ļƷֺ�����ÿ���������ӻ��ֲ���ӡ
		
		// �ҵ������ɫ
		if (FiringCharacter)
		{
			AStaticMeshActor* StaticMeshActor = Cast<AStaticMeshActor>(OtherActor);

			if (StaticMeshActor && StaticMeshActor->GetStaticMeshComponent())
			{
				// �ж��Ƿ�����Ŀ�����ư���"SM_ChamferCube"
				if (StaticMeshActor->GetStaticMeshComponent()->GetStaticMesh()->GetName().Contains(TEXT("SM_ChamferCube"))) {
					// �ж��Ƿ�������ҪĿ��
					if (StaticMeshActor->GetStaticMeshComponent()->GetStaticMesh()->GetName() == TEXT("SM_ChamferCubeChange"))
					{
						int32& HitCount = HitCounter.FindOrAdd(OtherActor); // ��ȡ���ʼ������������д���

						if (HitCount == 0)
						{
							// ��һ�����У���С�����С Y ��
							FVector NewScale = StaticMeshActor->GetActorScale3D() * FMath::Pow(0.5f, SmallTimes);
							StaticMeshActor->SetActorScale3D(NewScale);
						}
						else
						{
							StaticMeshActor->Destroy();
						}

						FiringCharacter->AddScore(Times * ScoreAmount);
					}
					else
					{
						int32& HitCount = HitCounter.FindOrAdd(OtherActor); // ��ȡ���ʼ������������д���

						if (HitCount == 0)
						{
							// ��һ�����У���С�����Сһ��
							FVector NewScale = StaticMeshActor->GetActorScale3D() * FMath::Pow(0.5f, SmallTimes);
							StaticMeshActor->SetActorScale3D(NewScale);
						}
						else
						{
							StaticMeshActor->Destroy();
						}
						FiringCharacter->AddScore(ScoreAmount);
					}
				}

			}
			// ֻ�ӷ֣�����С
			// �ж��ܷ��þ�̬������
			//if (StaticMeshActor && StaticMeshActor->GetStaticMeshComponent())
			//{
			//	// �ж��Ƿ�������ҪĿ��
			//	if (StaticMeshActor->GetStaticMeshComponent()->GetStaticMesh()->GetName() == TEXT("SM_ChamferCubeChange"))
			//	{
			//		// ���ӻ��֣�����ÿ����ײ���� Times ������ ScoreAmount ��
			//		FiringCharacter->AddScore(Times * ScoreAmount);
			//	}
			//	else
			//	{
			//		// ���ӻ��֣�����ÿ����ײ���� ScoreAmount ��
			//		FiringCharacter->AddScore(ScoreAmount);
			//		// UE_LOG(LogTemplateProjectile, Log, TEXT("sucess"));
			//	}
			//}
		}
		else 
		{
			UE_LOG(LogTemplateProjectile, Log, TEXT("false"));
		}

		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

		Destroy();
	}
	
}