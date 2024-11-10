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


void UIOToolkit_BPF::IO_SetDO(FString Device, FString Name, float Value)
{
	IO_GetDevice(Device)->SetDO(Name, Value);
}


void UIOToolkit_BPF::IO_SetDOKey(FString Device, TEnumAsByte<EIO_OAxisKey> Key, float Value)
{
	IO_GetDevice(Device)->SetDOKey(Key, Value);
}


void UIOToolkit_BPF::IO_SetDOKey_S(FString Device, FString Key, float Value)
{
	IO_GetDevice(Device)->SetDOKey_S(Key, Value);
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


float UIOToolkit_BPF::IO_GetDO(FString Device, FString Name)
{
	return IO_GetDevice(Device)->GetDO(Name);
}


float UIOToolkit_BPF::IO_GetDOKey(FString Device, TEnumAsByte<EIO_OAxisKey> Key)
{
	return IO_GetDevice(Device)->GetDOKey(Key);
}


float UIOToolkit_BPF::IO_GetDOKey_S(FString Device, FString Key)
{
	return IO_GetDevice(Device)->GetDOKey_S(Key);
}

bool UIOToolkit_BPF::IO_GetKey(FString Device, FString Key)
{
	return IO_GetDevice(Device)->GetKey_S(Key);
}

bool UIOToolkit_BPF::IO_GetKeyDown(FString Device, FString Key)
{
	return IO_GetDevice(Device)->GetKeyDown_S(Key);
}

float UIOToolkit_BPF::IO_GetKeyDownDuration(FString Device, FString Key)
{
	return IO_GetDevice(Device)->GetKeyDownDuration_S(Key);
}

bool UIOToolkit_BPF::IO_GetKeyUp(FString Device, FString Key)
{
	return IO_GetDevice(Device)->GetKeyUp_S(Key);
}

float UIOToolkit_BPF::IO_GetAxis(FString Device, FString InAxis)
{
	return io::IODeviceController::Instance()
		.GetIODevice(TCHAR_TO_ANSI(*Device))
		.GetAxis(TCHAR_TO_ANSI(*InAxis));
}

float UIOToolkit_BPF::IO_GetAxisKey(FString Device, FString AxisKey)
{
	return IO_GetDevice(Device)->GetAxisKey_S(AxisKey);
}