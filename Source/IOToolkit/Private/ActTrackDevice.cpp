// Fill out your copyright notice in the Description page of Project Settings.


#include "ActTrackDevice.h"

void UActTrackDevice::NotifyStart()
{
	SetDOKey(OAxis_00, 1);
	this->DOImmediate();
}

void UActTrackDevice::NotifyEnd()
{
	SetDOKey(OAxis_00, 0);
	this->DOImmediate();
}

void UActTrackDevice::NotifyButton(int buttonID)
{
	NotifyInput(EInputType::Button, buttonID);
}

void UActTrackDevice::NotifyInput(EInputType inputType, int inputID)
{
	EIO_OAxisKey _key = static_cast<EIO_OAxisKey>(static_cast<int>(inputType));
	SetDOKey(_key, inputID);
	this->DOImmediate();
}

void UActTrackDevice::NotifyAlarm(int alarmID)
{
	SetDOKey(OAxis_250, alarmID);
}
