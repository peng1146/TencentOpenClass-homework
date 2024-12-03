// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Homework1WeaponComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AHomework1Character;
#ifdef HOMEWORK1_Homework1WeaponComponent_generated_h
#error "Homework1WeaponComponent.generated.h already included, missing '#pragma once' in Homework1WeaponComponent.h"
#endif
#define HOMEWORK1_Homework1WeaponComponent_generated_h

#define FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1WeaponComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execEndPlay); \
	DECLARE_FUNCTION(execFire); \
	DECLARE_FUNCTION(execAttachWeapon);


#define FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1WeaponComponent_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHomework1WeaponComponent(); \
	friend struct Z_Construct_UClass_UHomework1WeaponComponent_Statics; \
public: \
	DECLARE_CLASS(UHomework1WeaponComponent, USkeletalMeshComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Homework1"), NO_API) \
	DECLARE_SERIALIZER(UHomework1WeaponComponent)


#define FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1WeaponComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UHomework1WeaponComponent(UHomework1WeaponComponent&&); \
	UHomework1WeaponComponent(const UHomework1WeaponComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHomework1WeaponComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHomework1WeaponComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UHomework1WeaponComponent) \
	NO_API virtual ~UHomework1WeaponComponent();


#define FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1WeaponComponent_h_11_PROLOG
#define FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1WeaponComponent_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1WeaponComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1WeaponComponent_h_14_INCLASS_NO_PURE_DECLS \
	FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1WeaponComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HOMEWORK1_API UClass* StaticClass<class UHomework1WeaponComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1WeaponComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
