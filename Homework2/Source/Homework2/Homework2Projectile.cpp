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

	// 默认积分值
	ScoreAmount = 10;

	// 缩小的默认倍数
	SmallTimes = 1;

	// 重要目标增加默认倍数
	Times = 2;

}

void AHomework2Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		// FiringCharacter = Cast<AHomework2Character>(GetOwner());
		// UE_LOG(LogTemp, Log, TEXT("Character Name: %s"), *FiringCharacter->GetName());
		// 调用Character的计分函数，每次命中增加积分并打印
		
		// 找到射击角色
		if (FiringCharacter)
		{
			AStaticMeshActor* StaticMeshActor = Cast<AStaticMeshActor>(OtherActor);

			if (StaticMeshActor && StaticMeshActor->GetStaticMeshComponent())
			{
				// 判断是否命中目标名称包含"SM_ChamferCube"
				if (StaticMeshActor->GetStaticMeshComponent()->GetStaticMesh()->GetName().Contains(TEXT("SM_ChamferCube"))) {
					// 判断是否命中重要目标
					if (StaticMeshActor->GetStaticMeshComponent()->GetStaticMesh()->GetName() == TEXT("SM_ChamferCubeChange"))
					{
						int32& HitCount = HitCounter.FindOrAdd(OtherActor); // 获取或初始化该物体的命中次数

						if (HitCount == 0)
						{
							// 第一次命中，缩小物体大小 Y 倍
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
						int32& HitCount = HitCounter.FindOrAdd(OtherActor); // 获取或初始化该物体的命中次数

						if (HitCount == 0)
						{
							// 第一次命中，缩小物体大小一倍
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
			// 只加分，不缩小
			// 判断能否获得静态网格体
			//if (StaticMeshActor && StaticMeshActor->GetStaticMeshComponent())
			//{
			//	// 判断是否命中重要目标
			//	if (StaticMeshActor->GetStaticMeshComponent()->GetStaticMesh()->GetName() == TEXT("SM_ChamferCubeChange"))
			//	{
			//		// 增加积分，假设每次碰撞增加 Times 倍数的 ScoreAmount 分
			//		FiringCharacter->AddScore(Times * ScoreAmount);
			//	}
			//	else
			//	{
			//		// 增加积分，假设每次碰撞增加 ScoreAmount 分
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