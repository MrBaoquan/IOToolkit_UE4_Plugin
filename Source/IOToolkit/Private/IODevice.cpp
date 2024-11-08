#include "IODevice.h"
#include "NetIODevice.h"
#include "IOToolkit/include/IODeviceController.h"

namespace io = IOToolkit;

UIODevice::UIODevice()
{
    // 在构造函数中初始化Device为空字符串
    DeviceName = TEXT("");
}

UIODevice::~UIODevice()
{
    UE_LOG(LogTemp, Warning, TEXT("UIODevice Destructor %s"), *DeviceName);
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

int32 UIODevice::DOImmediate()
{
    return io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .DOImmediate();
}

void UIODevice::SetDO(FString Target, float Value, TEnumAsByte<ESetDOType::Type> Type)
{
    auto& _device = io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName));
    if (Type == ESetDOType::OAction) {
        _device.SetDO(TCHAR_TO_ANSI(*Target), Value);
    }
    else {
        _device.SetDO(io::FKey(TCHAR_TO_ANSI(*Target)), Value);
    }
}

float UIODevice::GetDO(FString Target, TEnumAsByte<ESetDOType::Type> Type /*= ESetDOType::OAction*/)
{
	auto& _device = io::IODeviceController::Instance()
            .GetIODevice(TCHAR_TO_ANSI(*DeviceName));
    if (Type == ESetDOType::OAction) {
        return _device.GetDO(TCHAR_TO_ANSI(*Target));
    }
    else {
        return _device.GetDO(io::FKey(TCHAR_TO_ANSI(*Target)));
    }
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

void UIODevice::BindKey(FString InKey, TEnumAsByte<EIOEvent::Type> EventType, FActionDelegate InCallback)
{
    io::IODeviceController::Instance().GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .BindKey(TCHAR_TO_ANSI(*InKey), static_cast<io::InputEvent>(EventType.GetValue()), [=]() {
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
            NetIODevice->SetButtonPressed(OutputKey);
         });

        _extDev.BindKey(io::FKey(TCHAR_TO_ANSI(*InputKey)), io::InputEvent::IE_Released, [=]() {
            NetIODevice->SetButtonReleased(OutputKey);
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

void UIODevice::BindAxisKey(FString InAxisKey, FAxisDelegate InCallback)
{
    io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .BindAxisKey(TCHAR_TO_ANSI(*InAxisKey), [=](float val) {
        InCallback.ExecuteIfBound(val);
            });
}

void UIODevice::BindAxis(FString InAction, FAxisDelegate InCallback)
{
    io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .BindAxis(TCHAR_TO_ANSI(*InAction), [=](float val) {
        InCallback.ExecuteIfBound(val);
            });
}

bool UIODevice::GetKey(FString InKey)
{
    return io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .GetKey(TCHAR_TO_ANSI(*InKey));
}

bool UIODevice::GetKeyDown(FString InKey)
{
    return io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .GetKeyDown(TCHAR_TO_ANSI(*InKey));
}

float UIODevice::GetKeyDownDuration(FString InKey)
{
    return io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .GetKeyDownDuration(TCHAR_TO_ANSI(*InKey));
}

bool UIODevice::GetKeyUp(FString InKey)
{
    return io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .GetKeyUp(TCHAR_TO_ANSI(*InKey));
}

float UIODevice::GetAxis(FString InAxis)
{
    return io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .GetAxis(TCHAR_TO_ANSI(*InAxis));
}

float UIODevice::GetAxisKey(FString InAxisKey)
{
    return io::IODeviceController::Instance()
        .GetIODevice(TCHAR_TO_ANSI(*DeviceName))
        .GetAxisKey(TCHAR_TO_ANSI(*InAxisKey));
}
