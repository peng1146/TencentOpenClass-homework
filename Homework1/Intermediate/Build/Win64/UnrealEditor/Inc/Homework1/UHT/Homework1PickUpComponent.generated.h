// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Homework1PickUpComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class AHomework1Character;
class UPrimitiveComponent;
struct FHitResult;
#ifdef HOMEWORK1_Homework1PickUpComponent_generated_h
#error "Homework1PickUpComponent.generated.h already included, missing '#pragma once' in Homework1PickUpComponent.h"
#endif
#define HOMEWORK1_Homework1PickUpComponent_generated_h

#define FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1PickUpComponent_h_12_DELEGATE \
HOMEWORK1_API void FOnPickUp_DelegateWrapper(const FMulticastScriptDelegate& OnPickUp, AHomework1Character* PickUpCharacter);


#define FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1PickUpComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnSphereBeginOverlap);


#define FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1PickUpComponent_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHomework1PickUpComponent(); \
	friend struct Z_Construct_UClass_UHomework1PickUpComponent_Statics; \
public: \
	DECLARE_CLASS(UHomework1PickUpComponent, USphereComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Homework1"), NO_API) \
	DECLARE_SERIALIZER(UHomework1PickUpComponent)


#define FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1PickUpComponent_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UHomework1PickUpComponent(UHomework1PickUpComponent&&); \
	UHomework1PickUpComponent(const UHomework1PickUpComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHomework1PickUpComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHomework1PickUpComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UHomework1PickUpComponent) \
	NO_API virtual ~UHomework1PickUpComponent();


#define FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1PickUpComponent_h_14_PROLOG
#define FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1PickUpComponent_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1PickUpComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1PickUpComponent_h_17_INCLASS_NO_PURE_DECLS \
	FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1PickUpComponent_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HOMEWORK1_API UClass* StaticClass<class UHomework1PickUpComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1PickUpComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
