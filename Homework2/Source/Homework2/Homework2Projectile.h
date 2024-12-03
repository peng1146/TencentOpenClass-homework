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

	// ��ͼ�п��޸ĵĻ���ֵ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	int32 ScoreAmount; // ����ͼ�����û���

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	int32 Times; // ����ͼ�����ñ���

	// ���淢��õ���Ľ�ɫ
	UPROPERTY()
	AHomework2Character* FiringCharacter;

	// �� Homework2WeaponComponent.cpp �е���
	void SetFiringCharacter(AHomework2Character* Character)
	{
		FiringCharacter = Character;
	}

	// ׷��ÿ�����е��������д���
	UPROPERTY()
	TMap<AActor*, int32> HitCounter; // �������д���

	// ���к���С�ı���
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	int32 SmallTimes;

};

