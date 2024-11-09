// Fill out your copyright notice in the Description page of Project Settings.


#include "BindAxisKey.h"
#include "IOToolkit/include/IODeviceController.h"

namespace io = IOToolkit;

UBindAxisKey* UBindAxisKey::IO_SubscribeAxisKey(const UObject* WorldContextObject, FString Device, TEnumAsByte<EIO_Key> Key)
{
	UBindAxisKey* Node = NewObject<UBindAxisKey>();
	Node->WorldContextObject = WorldContextObject;
	Node->DeviceName = Device;
	Node->AxisKey = Key;
	Node->AxisKeyString = "";
	return Node;
}


UBindAxisKey* UBindAxisKey::IO_SubscribeAxisKey_S(const UObject* WorldContextObject, FString Device, FString Key)
{
	UBindAxisKey* Node = NewObject<UBindAxisKey>();
	Node->WorldContextObject = WorldContextObject;
	Node->DeviceName = Device;
	Node->AxisKeyString = Key;
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

	FString keyStr = UEnum::GetValueAsString(AxisKey);
	if (AxisKeyString != "") {
		keyStr = AxisKeyString;
	}
	io::IODeviceController::Instance().GetIODevice(TCHAR_TO_ANSI(*DeviceName))
		.BindAxisKey(TCHAR_TO_ANSI(*keyStr), [&](float val) {
		this->Update.Broadcast(val);
	});
}
