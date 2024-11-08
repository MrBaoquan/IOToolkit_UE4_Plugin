// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IODevice.h"
#include "IODeviceManager.generated.h"

/**
 * 
 */
UCLASS()
class UIODeviceManager : public UObject
{
	GENERATED_BODY()
public:
    static UIODeviceManager* Get();

    UIODevice* GetOrCreateIODevice(UObject* WorldContextObject, FString DeviceName);

private:
    UPROPERTY()
    TMap<FString, UIODevice*> DeviceMap;

    static UIODeviceManager* Instance;
};
