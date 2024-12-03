// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHomework1_init() {}
	HOMEWORK1_API UFunction* Z_Construct_UDelegateFunction_Homework1_OnPickUp__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Homework1;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Homework1()
	{
		if (!Z_Registration_Info_UPackage__Script_Homework1.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_Homework1_OnPickUp__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Homework1",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xDFD4BD03,
				0x472F5EE8,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Homework1.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Homework1.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Homework1(Z_Construct_UPackage__Script_Homework1, TEXT("/Script/Homework1"), Z_Registration_Info_UPackage__Script_Homework1, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xDFD4BD03, 0x472F5EE8));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
