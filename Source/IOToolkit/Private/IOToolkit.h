// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "Delegates/DelegateCombinations.h"
#include "Runtime/Launch/Resources/Version.h"

#if ENGINE_MINOR_VERSION >= 20 || ENGINE_MAJOR_VERSION >=5
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#elif ENGINE_MINOR_VERSION >= 15
#include "ModuleManager.h"
#include "IPluginManager.h"
#endif

class FIOToolkitModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	/** Handle to the test dll we will load */
	void*	IOToolkitLibraryHandle;
};