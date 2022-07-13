// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealStudy/UnrealStudyGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnrealStudyGameMode() {}
// Cross Module References
	UNREALSTUDY_API UClass* Z_Construct_UClass_AUnrealStudyGameMode_NoRegister();
	UNREALSTUDY_API UClass* Z_Construct_UClass_AUnrealStudyGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_UnrealStudy();
// End Cross Module References
	void AUnrealStudyGameMode::StaticRegisterNativesAUnrealStudyGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AUnrealStudyGameMode);
	UClass* Z_Construct_UClass_AUnrealStudyGameMode_NoRegister()
	{
		return AUnrealStudyGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AUnrealStudyGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AUnrealStudyGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealStudy,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUnrealStudyGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "UnrealStudyGameMode.h" },
		{ "ModuleRelativePath", "UnrealStudyGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AUnrealStudyGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUnrealStudyGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AUnrealStudyGameMode_Statics::ClassParams = {
		&AUnrealStudyGameMode::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AUnrealStudyGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AUnrealStudyGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AUnrealStudyGameMode()
	{
		if (!Z_Registration_Info_UClass_AUnrealStudyGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AUnrealStudyGameMode.OuterSingleton, Z_Construct_UClass_AUnrealStudyGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AUnrealStudyGameMode.OuterSingleton;
	}
	template<> UNREALSTUDY_API UClass* StaticClass<AUnrealStudyGameMode>()
	{
		return AUnrealStudyGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AUnrealStudyGameMode);
	struct Z_CompiledInDeferFile_FID_UnrealStudy_Source_UnrealStudy_UnrealStudyGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealStudy_Source_UnrealStudy_UnrealStudyGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AUnrealStudyGameMode, AUnrealStudyGameMode::StaticClass, TEXT("AUnrealStudyGameMode"), &Z_Registration_Info_UClass_AUnrealStudyGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AUnrealStudyGameMode), 2484021692U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealStudy_Source_UnrealStudy_UnrealStudyGameMode_h_3667259890(TEXT("/Script/UnrealStudy"),
		Z_CompiledInDeferFile_FID_UnrealStudy_Source_UnrealStudy_UnrealStudyGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealStudy_Source_UnrealStudy_UnrealStudyGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
