// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "IOToolkit.h"
#include "Core.h"
#include "Runtime/Launch/Resources/Version.h"

#if ENGINE_MINOR_VERSION >= 23
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#elif ENGINE_MINOR_VERSION >= 15
#include "ModuleManager.h"
#include "IPluginManager.h"
#endif
#include "IODeviceController.h"

#define LOCTEXT_NAMESPACE "FIOToolkitModule"

void FIOToolkitModule::StartupModule()
{
	UE_LOG(LogTemp, Log, TEXT("--------- start up ---------"));

	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Get the base directory of this plugin
#if ENGINE_MINOR_VERSION >= 23
	FString BaseDir = FPaths::ProjectDir();
#elif ENGINE_MINOR_VERSION >= 15
	FString BaseDir = FPaths::GameDir();
#endif
	
	// Add on the relative location of the third party dll and load it
	FString LibraryPath;
#if PLATFORM_WINDOWS
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Binaries/Win64/IODevice.dll"));
#endif // PLATFORM_WINDOWS

	IOToolkitLibraryHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;

	if (!IOToolkitLibraryHandle)
	{
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("Load IOToolkit Failed", "Failed to load IOToolkit library"));
	}
}

void FIOToolkitModule::ShutdownModule()
{
	UE_LOG(LogTemp, Log, TEXT("--------- shutdown ---------"));

	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Free the dll handle
	FPlatformProcess::FreeDllHandle(IOToolkitLibraryHandle);
	IOToolkitLibraryHandle = nullptr;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FIOToolkitModule, IOToolkit)