// Fill out your copyright notice in the Description page of Project Settings.

#include "IOToolkit_BPF.h"
#include "IOToolkit.h"
#include "IODeviceController.h"
namespace io = IOToolkit;

void UIOToolkit_BPF::IO_Load()
{
	IO_ClearBindings();
	io::IODeviceController::Instance().Load();
}

void UIOToolkit_BPF::IO_Update()
{
	io::IODeviceController::Instance().Update();
}

void UIOToolkit_BPF::IO_Unload()
{
	io::IODeviceController::Instance().Unload();
}

void UIOToolkit_BPF::IO_ClearBindings()
{
	io::IODeviceController::Instance().ClearBindings();
}

void UIOToolkit_BPF::IO_SetDO(FString Device, FString Target, float Value, TEnumAsByte<ESetDOType> Type /*= DOType.OAction*/)
{
	if (Device.IsEmpty()) {
		UE_LOG(LogTemp, Warning, TEXT("Can not SetDo on an empty device."));
		return;
	}
	auto& _device = io::IODeviceController::Instance()
		.GetIODevice(TCHAR_TO_ANSI(*Device));
	if (Type == ESetDOType::OAction) {
		_device.SetDO(TCHAR_TO_ANSI(*Device), Value);
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
