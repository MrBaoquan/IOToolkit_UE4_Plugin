// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Runtime/Launch/Resources/Version.h"

#if ENGINE_MINOR_VERSION >=20
#include "Modules/ModuleManager.h"
#elif ENGINE_MINOR_VERSION >=15
#include "ModuleManager.h"
#endif

UENUM(BlueprintType)
namespace ESetDOType {
	enum Type{
		OAxis,
		OAction
	};
}

UENUM(BlueprintType)
namespace EIOEvent {
	enum Type {
		IE_Pressed = 0,
		IE_Released = 1,
		IE_Repeat = 2,
		IE_DoubleClick = 3,
		IE_Axis = 4,
		IE_MAX = 5,
	};
}

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