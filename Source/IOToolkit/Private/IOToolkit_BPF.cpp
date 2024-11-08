// Fill out your copyright notice in the Description page of Project Settings.

#include "IOToolkit_BPF.h"
#include "IODevice.h"
#include "IOToolkit/include/IODeviceController.h"
namespace io = IOToolkit;

void UIOToolkit_BPF::IO_Load()
{
	UIODevice::ClearIODevices();
	IO_ClearBindings();
	io::IODeviceController::Instance().Load();
}

void UIOToolkit_BPF::IO_Update()
{
	io::IODeviceController::Instance().Update();
}

void UIOToolkit_BPF::IO_Unload()
{
	UIODevice::ClearIODevices();
	io::IODeviceController::Instance().Unload();
}

void UIOToolkit_BPF::IO_ClearBindings()
{
	io::IODeviceController::Instance().ClearBindings();
}

UIODevice* UIOToolkit_BPF::IO_GetDevice(FString DeviceName /*= TEXT("")*/)
{
	return UIODevice::GetOrCreateIODevice(DeviceName);
}

int32 UIOToolkit_BPF::IO_DOImmediate(FString Device)
{
	return io::IODeviceController::Instance()
		.GetIODevice(TCHAR_TO_ANSI(*Device))
		.DOImmediate();
}

void UIOToolkit_BPF::IO_SetDO(FString Device, FString Target, float Value, TEnumAsByte<ESetDOType::Type> Type /*= DOType.OAction*/)
{
	if (Device.IsEmpty()) {
		UE_LOG(LogTemp, Warning, TEXT("Can not SetDo on an empty device."));
		return;
	}
	auto& _device = io::IODeviceController::Instance()
		.GetIODevice(TCHAR_TO_ANSI(*Device));
	if (Type == ESetDOType::OAction) {
		_device.SetDO(TCHAR_TO_ANSI(*Target), Value);
	}
	else {
		_device.SetDO(io::FKey(TCHAR_TO_ANSI(*Target)), Value);
	}
}

void UIOToolkit_BPF::IO_SetDOOn(FString Device, FString OAction)
{
	io::IODeviceController::Instance()
		.GetIODevice(TCHAR_TO_ANSI(*Device))
		.SetDOOn(TCHAR_TO_ANSI(*OAction));

}

void UIOToolkit_BPF::IO_SetDOOff(FString Device, FString OAction)
{
	io::IODeviceController::Instance()
		.GetIODevice(TCHAR_TO_ANSI(*Device))
		.SetDOOff(TCHAR_TO_ANSI(*OAction));
}

void UIOToolkit_BPF::IO_BindKey(FString Device, FString InKey, TEnumAsByte<EIOEvent::Type> EventType, FActionDelegate InCallback)
{
	io::IODeviceController::Instance().GetIODevice(TCHAR_TO_ANSI(*Device))
		.BindKey(TCHAR_TO_ANSI(*InKey), static_cast<io::InputEvent>(EventType.GetValue()), [=]() {
			InCallback.ExecuteIfBound();
		});
}

void UIOToolkit_BPF::IO_BindAction(FString Device, FString InAction, TEnumAsByte<EIOEvent::Type> EventType, FActionDelegateWithKey InCallback)
{
	io::IODeviceController::Instance()
		.GetIODevice(TCHAR_TO_ANSI(*Device))
		.BindAction(TCHAR_TO_ANSI(*InAction), static_cast<io::InputEvent>(EventType.GetValue()), [=](io::FKey InKey) {
			InCallback.ExecuteIfBound(FString(InKey.GetName()));
		});
}

void UIOToolkit_BPF::IO_BindAxisKey(FString Device, FString InAxisKey, FAxisDelegate InCallback)
{
	io::IODeviceController::Instance()
		.GetIODevice(TCHAR_TO_ANSI(*Device))
		.BindAxisKey(TCHAR_TO_ANSI(*InAxisKey), [=](float val) {
			InCallback.ExecuteIfBound(val);
		});
}

void UIOToolkit_BPF::IO_BindAxis(FString Device, FString InAxis, FAxisDelegate InCallback)
{
	io::IODeviceController::Instance()
		.GetIODevice(TCHAR_TO_ANSI(*Device))
		.BindAxis(TCHAR_TO_ANSI(*InAxis), [=](float val) {
			InCallback.ExecuteIfBound(val);
		});
}

bool UIOToolkit_BPF::IO_GetKey(FString Device, FString InKey)
{
	return io::IODeviceController::Instance()
		.GetIODevice(TCHAR_TO_ANSI(*Device))
		.GetKey(TCHAR_TO_ANSI(*InKey));
}

bool UIOToolkit_BPF::IO_GetKeyDown(FString Device, FString InKey)
{
	return io::IODeviceController::Instance()
		.GetIODevice(TCHAR_TO_ANSI(*Device))
		.GetKeyDown(TCHAR_TO_ANSI(*InKey));
}

float UIOToolkit_BPF::IO_GetKeyDownDuration(FString Device, FString InKey)
{
	return io::IODeviceController::Instance()
		.GetIODevice(TCHAR_TO_ANSI(*Device))
		.GetKeyDownDuration(TCHAR_TO_ANSI(*InKey));
}

bool UIOToolkit_BPF::IO_GetKeyUp(FString Device, FString InKey)
{
	return io::IODeviceController::Instance()
		.GetIODevice(TCHAR_TO_ANSI(*Device))
		.GetKeyUp(TCHAR_TO_ANSI(*InKey));
}

float UIOToolkit_BPF::IO_GetAxis(FString Device, FString InAxis)
{
	return io::IODeviceController::Instance()
		.GetIODevice(TCHAR_TO_ANSI(*Device))
		.GetAxis(TCHAR_TO_ANSI(*InAxis));
}

float UIOToolkit_BPF::IO_GetAxisKey(FString Device, FString InAxisKey)
{
	return io::IODeviceController::Instance()
		.GetIODevice(TCHAR_TO_ANSI(*Device))
		.GetAxis(TCHAR_TO_ANSI(*InAxisKey));
}