// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Homework1Projectile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef HOMEWORK1_Homework1Projectile_generated_h
#error "Homework1Projectile.generated.h already included, missing '#pragma once' in Homework1Projectile.h"
#endif
#define HOMEWORK1_Homework1Projectile_generated_h

#define FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1Projectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnHit);


#define FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1Projectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAHomework1Projectile(); \
	friend struct Z_Construct_UClass_AHomework1Projectile_Statics; \
public: \
	DECLARE_CLASS(AHomework1Projectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Homework1"), NO_API) \
	DECLARE_SERIALIZER(AHomework1Projectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1Projectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AHomework1Projectile(AHomework1Projectile&&); \
	AHomework1Projectile(const AHomework1Projectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHomework1Projectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHomework1Projectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AHomework1Projectile) \
	NO_API virtual ~AHomework1Projectile();


#define FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1Projectile_h_12_PROLOG
#define FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1Projectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1Projectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1Projectile_h_15_INCLASS_NO_PURE_DECLS \
	FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1Projectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HOMEWORK1_API UClass* StaticClass<class AHomework1Projectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1Projectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
