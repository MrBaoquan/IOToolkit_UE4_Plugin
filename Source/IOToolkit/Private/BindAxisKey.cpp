// Fill out your copyright notice in the Description page of Project Settings.


#include "BindAxisKey.h"
#include "IODeviceController.h"

namespace io = IOToolkit;

UBindAxisKey* UBindAxisKey::IO_SubscribeAxisKey(const UObject* WorldContextObject, FString Device, FString AxisKey)
{
	UBindAxisKey* Node = NewObject<UBindAxisKey>();
	Node->WorldContextObject = WorldContextObject;
	Node->DeviceName = Device;
	Node->AxisKeyName = AxisKey;
	return Node;
}

void UBindAxisKey::Activate()
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

	io::IODeviceController::Instance().GetIODevice(TCHAR_TO_ANSI(*DeviceName))
		.BindAxisKey(TCHAR_TO_ANSI(*AxisKeyName), [&](float val) {
		this->Update.Broadcast(val);
	});
}
