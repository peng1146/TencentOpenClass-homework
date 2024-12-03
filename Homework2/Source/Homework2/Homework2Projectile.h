// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Logging/LogMacros.h"
#include "Math/UnrealMathUtility.h"
#include "Homework2Projectile.generated.h"

class AHomework2Character;
class USphereComponent;
class UProjectileMovementComponent;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateProjectile, Log, All);

UCLASS(config=Game)
class AHomework2Projectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

public:
	AHomework2Projectile();


	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }

	// 蓝图中可修改的积分值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	int32 ScoreAmount; // 在蓝图中设置积分

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	int32 Times; // 在蓝图中设置倍数

	// 保存发射该弹丸的角色
	UPROPERTY()
	AHomework2Character* FiringCharacter;

	// 在 Homework2WeaponComponent.cpp 中调用
	void SetFiringCharacter(AHomework2Character* Character)
	{
		FiringCharacter = Character;
	}

	// 追踪每个命中的物体命中次数
	UPROPERTY()
	TMap<AActor*, int32> HitCounter; // 物体命中次数

	// 命中后缩小的倍数
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	int32 SmallTimes;

};

