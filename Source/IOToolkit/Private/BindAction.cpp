// Fill out your copyright notice in the Description page of Project Settings.

#include "BindAction.h"
#include "IOToolkit/include/IODeviceController.h"

namespace io = IOToolkit;

UBindAction* UBindAction::IO_SubscribeAction(const UObject* WorldContextObject, FString Device, FString Action)
{
	UBindAction* Node = NewObject<UBindAction>();
	Node->WorldContextObject = WorldContextObject;
	Node->DeviceName = Device;
	Node->ActionName = Action;
	return Node;
}

void UBindAction::Activate()
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
	
	_device.BindAction(TCHAR_TO_ANSI(*ActionName), io::IE_Pressed, [&](io::FKey InKey) {
		this->IE_Pressed.Broadcast(FString(InKey.GetName()));
	});

	_device.BindAction(TCHAR_TO_ANSI(*ActionName), io::IE_Released, [&](io::FKey InKey) {
		this->IE_Released.Broadcast(FString(InKey.GetName()));
	});
}
