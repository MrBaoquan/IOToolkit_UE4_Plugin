﻿#include "IODevice.h"
#include "NetIODevice.h"
#include "ModbusDevice.h"
#include "IOToolkit/include/IODeviceController.h"

namespace io = IOToolkit;

UIODevice::UIODevice()
{
    // 在构造函数中初始化Device为空字符串
    DeviceName = TEXT("");
}

UIODevice::~UIODevice()
{
    //UE_LOG(LogTemp, Warning, TEXT("UIODevice Destructor %s"), *DeviceName);
}

TMap<FString, UIODevice*> UIODevice::DeviceMap;

UIODevice* UIODevice::GetOrCreateIODevice(FString Name)
{
    // 检查是否存在有效的设备实例
    if (DeviceMap.Contains(Name))
    {
        UIODevice* ExistingDevice = DeviceMap[Name];
        if (IsValid(ExistingDevice))
        {
            return ExistingDevice;
        }
    }

    auto& _device = io::IODeviceController::Instance().GetIODevice(TCHAR_TO_ANSI(*Name));
    FString dllName = _device.DllName();
    FString ioType = _device.IOType();
    int32 idx = _device.Index();

    UIODevice* NewIODevice = nullptr;
    if (dllName == "NETIO") {
        NewIODevice = NewObject<UNetIODevice>(GetTransientPackage());
    }
    else if (dllName == "MODBUS") {
        NewIODevice = NewObject<UModbusDevice>(GetTransientPackage());
    }
    else {
        NewIODevice = NewObject<UIODevice>(GetTransientPackage());
    }

    // 创建新设备实例，指定Outer以管理生命周期
    
    NewIODevice->AddToRoot();
    NewIODevice->Initialize(Name);

    // 添加或替换设备实例
    DeviceMap.Add(Name, NewIODevice);

    return NewIODevice;
}

void UIODevice::ClearIODevices()
{
    for (auto& pair : DeviceMap) {
        pair.Value->RemoveFromRoot();
    }
    DeviceMap.Empty();
}

void UIODevice::Initialize(FString Name)
{
    this->DeviceName = Name;
}

void UIODevice::ClearBingings()
{
    auto& _device = io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName));
    _device.ClearBindings();
}

int32 UIODevice::DOImmediate()
{
    return io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .DOImmediate();
}

void UIODevice::SetDO(FString Name, float Value)
{
    auto& _device = io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName));
    _device.SetDO(TCHAR_TO_ANSI(*Name), Value);
}

void UIODevice::SetDOKey(TEnumAsByte<EIO_OAxisKey> Key, float Value)
{
    auto keyText= UEnum::GetValueAsString(Key);
    auto& _device = io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName));
    _device.SetDO(io::FKey(TCHAR_TO_ANSI(*keyText)), Value);
}

void UIODevice::SetDOKey_S(FString Key, float Value)
{
    auto& _device = io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName));
    _device.SetDO(io::FKey(TCHAR_TO_ANSI(*Key)), Value);
}

float UIODevice::GetDO(FString Name)
{
    auto& _device = io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName));
    return _device.GetDO(TCHAR_TO_ANSI(*Name));
}

float UIODevice::GetDOKey(TEnumAsByte<EIO_OAxisKey> Key)
{
    auto& _device = io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName));
    auto keyText = UEnum::GetValueAsString(Key);
    return _device.GetDO(io::FKey(TCHAR_TO_ANSI(*keyText)));
}

float UIODevice::GetDOKey_S(FString Key)
{
    auto& _device = io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName));
    return _device.GetDO(io::FKey(TCHAR_TO_ANSI(*Key)));
}

void UIODevice::SetDOOn(FString OAction)
{
    io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .SetDOOn(TCHAR_TO_ANSI(*OAction));
}

void UIODevice::SetDOOff(FString OAction)
{
    io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .SetDOOff(TCHAR_TO_ANSI(*OAction));
}


bool UIODevice::GetKey(TEnumAsByte<EIO_Key> Key)
{
    return GetKey_S(UEnum::GetValueAsString(Key));
}

void UIODevice::BindKey(TEnumAsByte<EIO_Key> Key, TEnumAsByte<EIOEvent::Type> EventType, FActionDelegate InCallback)
{
    FString keyStr = UEnum::GetValueAsString(Key);
    BindKey_S(keyStr, EventType, InCallback);
}

void UIODevice::BindKey_S(FString Key, TEnumAsByte<EIOEvent::Type> EventType, FActionDelegate InCallback)
{
    io::IODeviceController::Instance().GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .BindKey(TCHAR_TO_ANSI(*Key), static_cast<io::InputEvent>(EventType.GetValue()), [=]() {
            InCallback.ExecuteIfBound();
        });
}

void UIODevice::PropagateDIEvents(UNetIODevice* NetIODevice, int32 StartChannel, int32 Count)
{
    for (int32 Idx = StartChannel; Idx < StartChannel + Count; ++Idx)
    {
        FString OutputKey = FString::Printf(TEXT("OAxis_%02d"), Idx);
        FString InputKey = FString::Printf(TEXT("Button_%02d"), Idx);

        auto& _netDev = io::IODeviceController::Instance().GetIODevice(TCHAR_TO_ANSI(*NetIODevice->DeviceName));
        auto& _extDev = io::IODeviceController::Instance().GetIODevice(TCHAR_TO_ANSI(*DeviceName));

        _extDev.BindKey(io::FKey(TCHAR_TO_ANSI(*InputKey)), io::InputEvent::IE_Pressed, [=]() {
            NetIODevice->SetRemoteKeyDown(static_cast<EIO_ButtonKey::Type>(Idx));
         });

        _extDev.BindKey(io::FKey(TCHAR_TO_ANSI(*InputKey)), io::InputEvent::IE_Released, [=]() {
            NetIODevice->SetRemoteKeyUp(static_cast<EIO_ButtonKey::Type>(Idx));
         });
    }
}

void UIODevice::BindAction(FString InAction, TEnumAsByte<EIOEvent::Type> EventType, FActionDelegateWithKey InCallback)
{
    io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .BindAction(TCHAR_TO_ANSI(*InAction), static_cast<io::InputEvent>(EventType.GetValue()), [=](io::FKey InKey) {
            InCallback.ExecuteIfBound(FString(InKey.GetName()));
        });
}

void UIODevice::BindAxisKey(TEnumAsByte<EIO_Key> AxisKey, FAxisDelegate InCallback)
{
    FString keyStr = UEnum::GetValueAsString(AxisKey);
    BindAxisKey_S(keyStr, InCallback);
}

void UIODevice::BindAxisKey_S(FString Key, FAxisDelegate InCallback)
{
    io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .BindAxisKey(TCHAR_TO_ANSI(*Key), [=](float val) {
            InCallback.ExecuteIfBound(val);
        });
}

void UIODevice::BindAxis(FString Name, FAxisDelegate InCallback)
{
    io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .BindAxis(TCHAR_TO_ANSI(*Name), [=](float val) {
            InCallback.ExecuteIfBound(val);
        });
}

bool UIODevice::GetKey_S(FString Key)
{
    return io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .GetKey(TCHAR_TO_ANSI(*Key));
}


bool UIODevice::GetKeyDown(TEnumAsByte<EIO_Key> Key)
{
    return GetKeyDown_S(UEnum::GetValueAsString(Key));
}

bool UIODevice::GetKeyDown_S(FString Key)
{
    return io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .GetKeyDown(TCHAR_TO_ANSI(*Key));
}


float UIODevice::GetKeyDownDuration(TEnumAsByte<EIO_Key> Key)
{
    return GetKeyDownDuration_S(UEnum::GetValueAsString(Key));
}

float UIODevice::GetKeyDownDuration_S(FString Key)
{
    return io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .GetKeyDownDuration(TCHAR_TO_ANSI(*Key));
}


bool UIODevice::GetKeyUp(TEnumAsByte<EIO_Key> Key)
{
    return GetKeyUp_S(UEnum::GetValueAsString(Key));
}

bool UIODevice::GetKeyUp_S(FString Key)
{
    return io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .GetKeyUp(TCHAR_TO_ANSI(*Key));
}

float UIODevice::GetAxis(FString InAxis)
{
    return io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .GetAxis(TCHAR_TO_ANSI(*InAxis));
}


float UIODevice::GetAxisKey(TEnumAsByte<EIO_Key> AxisKey)
{
    return GetAxisKey_S(UEnum::GetValueAsString(AxisKey));
}

float UIODevice::GetAxisKey_S(FString AxisKey)
{
    return io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .GetAxisKey(TCHAR_TO_ANSI(*AxisKey));
}
