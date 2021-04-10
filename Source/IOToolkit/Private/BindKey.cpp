// Fill out your copyright notice in the Description page of Project Settings.


#include "BindKey.h"
#include "IODeviceController.h"

namespace io = IOToolkit;

UBindKey* UBindKey::IO_SubscribeKey(const UObject* WorldContextObject, FString Device, FString Key)
{
	UBindKey* Node = NewObject<UBindKey>();
	Node->WorldContextObject = WorldContextObject;
	Node->DeviceName = Device;
	Node->KeyName = Key;
	return Node;
}

void UBindKey::Activate()
{
	if (nullptr == WorldContextObject)
	{
		FFrame::KismetExecutionMessage(TEXT("Invalid WorldContextObject."),
			ELogVerbosity::Error);
		return;
	}

	if (Active)
	{
		FFrame::KismetExecutionMessage(TEXT("DelayLoop is already running."),
			ELogVerbosity::Warning);
	}

	Active = true;
	auto& _device = io::IODeviceController::Instance().GetIODevice(TCHAR_TO_ANSI(*DeviceName));

	_device.BindKey(TCHAR_TO_ANSI(*KeyName), io::IE_Pressed, [&]() {
		this->IE_Pressed.Broadcast();
	});

	_device.BindKey(TCHAR_TO_ANSI(*KeyName), io::IE_Released, [&]() {
		this->IE_Released.Broadcast();
	});
}
