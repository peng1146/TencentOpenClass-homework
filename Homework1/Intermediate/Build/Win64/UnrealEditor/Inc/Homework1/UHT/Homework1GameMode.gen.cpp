// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Homework1/Homework1GameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHomework1GameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
HOMEWORK1_API UClass* Z_Construct_UClass_AHomework1GameMode();
HOMEWORK1_API UClass* Z_Construct_UClass_AHomework1GameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_Homework1();
// End Cross Module References

// Begin Class AHomework1GameMode
void AHomework1GameMode::StaticRegisterNativesAHomework1GameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AHomework1GameMode);
UClass* Z_Construct_UClass_AHomework1GameMode_NoRegister()
{
	return AHomework1GameMode::StaticClass();
}
struct Z_Construct_UClass_AHomework1GameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Homework1GameMode.h" },
		{ "ModuleRelativePath", "Homework1GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHomework1GameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AHomework1GameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Homework1,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHomework1GameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AHomework1GameMode_Statics::ClassParams = {
	&AHomework1GameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHomework1GameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AHomework1GameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AHomework1GameMode()
{
	if (!Z_Registration_Info_UClass_AHomework1GameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHomework1GameMode.OuterSingleton, Z_Construct_UClass_AHomework1GameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AHomework1GameMode.OuterSingleton;
}
template<> HOMEWORK1_API UClass* StaticClass<AHomework1GameMode>()
{
	return AHomework1GameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AHomework1GameMode);
AHomework1GameMode::~AHomework1GameMode() {}
// End Class AHomework1GameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1GameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AHomework1GameMode, AHomework1GameMode::StaticClass, TEXT("AHomework1GameMode"), &Z_Registration_Info_UClass_AHomework1GameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHomework1GameMode), 1711399856U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1GameMode_h_1597427275(TEXT("/Script/Homework1"),
	Z_CompiledInDeferFile_FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1GameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TencentOpenClass_homework_Homework1_Source_Homework1_Homework1GameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
