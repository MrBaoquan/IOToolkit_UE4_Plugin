// Fill out your copyright notice in the Description page of Project Settings.


#include "IODeviceManager.h"


UIODeviceManager* UIODeviceManager::Get()
{
    if (!Instance)
    {
        Instance = NewObject<UIODeviceManager>();
        Instance->AddToRoot(); // ��ֹGC
    }
    return Instance;
}

UIODevice* UIODeviceManager::GetOrCreateIODevice(UObject* WorldContextObject, FString DeviceName)
{
    if (DeviceMap.Contains(DeviceName))
    {
        return DeviceMap[DeviceName];
    }

    // ����豸�����ڣ��򴴽�һ���µ�
    UWorld* World = nullptr;
    if (WorldContextObject)
    {
        World = WorldContextObject->GetWorld();
    }

    if (!World && GEngine)
    {
        World = GEngine->GetWorld();
    }

    if (!World)
    {
        UE_LOG(LogTemp, Warning, TEXT("Could not find a valid UWorld."));
        return nullptr;
    }

    UIODevice* NewIODevice = NewObject<UIODevice>(World);
    if (NewIODevice)
    {
        NewIODevice->Initialize(DeviceName);
        DeviceMap.Add(DeviceName, NewIODevice);
    }
    return NewIODevice;
}

UIODeviceManager* UIODeviceManager::Instance = nullptr;
