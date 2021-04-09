// Fill out your copyright notice in the Description page of Project Settings.

#include "BindAxis.h"
#include "IOToolkit.h"
#include "IODeviceController.h"

namespace io = IOToolkit;


UBindAxis* UBindAxis::IOSubscribeAxis(const UObject* WorldContextObject, FString Device, FString Axis)
{
	UBindAxis* Node = NewObject<UBindAxis>();
	Node->WorldContextObject = WorldContextObject;
	Node->DeviceName = Device;
	Node->AxisName = Axis;
	return Node;
}

void UBindAxis::Activate()
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
		.BindAxis(TCHAR_TO_ANSI(*AxisName), [&](float val) {
			this->Update.Broadcast(val);
		});
}
