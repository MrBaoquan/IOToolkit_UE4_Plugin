// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Runtime/Launch/Resources/Version.h"

#if ENGINE_MINOR_VERSION >=23
#include "Modules/ModuleManager.h"
#elif ENGINE_MINOR_VERSION >=15
#include "ModuleManager.h"
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