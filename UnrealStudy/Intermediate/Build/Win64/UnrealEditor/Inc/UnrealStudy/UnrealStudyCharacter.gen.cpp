// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealStudy/UnrealStudyCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnrealStudyCharacter() {}
// Cross Module References
	UNREALSTUDY_API UClass* Z_Construct_UClass_AUnrealStudyCharacter_NoRegister();
	UNREALSTUDY_API UClass* Z_Construct_UClass_AUnrealStudyCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_UnrealStudy();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AUnrealStudyCharacter::execOpenInGameMenu)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OpenInGameMenu();
		P_NATIVE_END;
	}
	void AUnrealStudyCharacter::StaticRegisterNativesAUnrealStudyCharacter()
	{
		UClass* Class = AUnrealStudyCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OpenInGameMenu", &AUnrealStudyCharacter::execOpenInGameMenu },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AUnrealStudyCharacter_OpenInGameMenu_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AUnrealStudyCharacter_OpenInGameMenu_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UnrealStudyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AUnrealStudyCharacter_OpenInGameMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AUnrealStudyCharacter, nullptr, "OpenInGameMenu", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AUnrealStudyCharacter_OpenInGameMenu_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AUnrealStudyCharacter_OpenInGameMenu_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AUnrealStudyCharacter_OpenInGameMenu()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AUnrealStudyCharacter_OpenInGameMenu_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AUnrealStudyCharacter);
	UClass* Z_Construct_UClass_AUnrealStudyCharacter_NoRegister()
	{
		return AUnrealStudyCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AUnrealStudyCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TurnRateGamepad_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TurnRateGamepad;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AUnrealStudyCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealStudy,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AUnrealStudyCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AUnrealStudyCharacter_OpenInGameMenu, "OpenInGameMenu" }, // 2466627043
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUnrealStudyCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "UnrealStudyCharacter.h" },
		{ "ModuleRelativePath", "UnrealStudyCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUnrealStudyCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Camera boom positioning the camera behind the character */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UnrealStudyCharacter.h" },
		{ "ToolTip", "Camera boom positioning the camera behind the character" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUnrealStudyCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AUnrealStudyCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AUnrealStudyCharacter_Statics::NewProp_CameraBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AUnrealStudyCharacter_Statics::NewProp_CameraBoom_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUnrealStudyCharacter_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Follow camera */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UnrealStudyCharacter.h" },
		{ "ToolTip", "Follow camera" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUnrealStudyCharacter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AUnrealStudyCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AUnrealStudyCharacter_Statics::NewProp_FollowCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AUnrealStudyCharacter_Statics::NewProp_FollowCamera_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUnrealStudyCharacter_Statics::NewProp_TurnRateGamepad_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */" },
		{ "ModuleRelativePath", "UnrealStudyCharacter.h" },
		{ "ToolTip", "Base turn rate, in deg/sec. Other scaling may affect final turn rate." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AUnrealStudyCharacter_Statics::NewProp_TurnRateGamepad = { "TurnRateGamepad", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AUnrealStudyCharacter, TurnRateGamepad), METADATA_PARAMS(Z_Construct_UClass_AUnrealStudyCharacter_Statics::NewProp_TurnRateGamepad_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AUnrealStudyCharacter_Statics::NewProp_TurnRateGamepad_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AUnrealStudyCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnrealStudyCharacter_Statics::NewProp_CameraBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnrealStudyCharacter_Statics::NewProp_FollowCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnrealStudyCharacter_Statics::NewProp_TurnRateGamepad,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AUnrealStudyCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUnrealStudyCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AUnrealStudyCharacter_Statics::ClassParams = {
		&AUnrealStudyCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AUnrealStudyCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AUnrealStudyCharacter_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AUnrealStudyCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AUnrealStudyCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AUnrealStudyCharacter()
	{
		if (!Z_Registration_Info_UClass_AUnrealStudyCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AUnrealStudyCharacter.OuterSingleton, Z_Construct_UClass_AUnrealStudyCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AUnrealStudyCharacter.OuterSingleton;
	}
	template<> UNREALSTUDY_API UClass* StaticClass<AUnrealStudyCharacter>()
	{
		return AUnrealStudyCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AUnrealStudyCharacter);
	struct Z_CompiledInDeferFile_FID_UnrealStudy_Source_UnrealStudy_UnrealStudyCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealStudy_Source_UnrealStudy_UnrealStudyCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AUnrealStudyCharacter, AUnrealStudyCharacter::StaticClass, TEXT("AUnrealStudyCharacter"), &Z_Registration_Info_UClass_AUnrealStudyCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AUnrealStudyCharacter), 1809551200U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealStudy_Source_UnrealStudy_UnrealStudyCharacter_h_1298529598(TEXT("/Script/UnrealStudy"),
		Z_CompiledInDeferFile_FID_UnrealStudy_Source_UnrealStudy_UnrealStudyCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealStudy_Source_UnrealStudy_UnrealStudyCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
