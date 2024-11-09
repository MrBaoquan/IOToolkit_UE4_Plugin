// Fill out your copyright notice in the Description page of Project Settings.


#include "ModbusDevice.h"

void UModbusDevice::SetSlaveID(int Address)
{
	SetDOKey(OAxis_00, 1);
	SetDOKey(OAxis_01, Address);
	DOImmediate();
}

void UModbusDevice::WriteCoil(int Address, bool Value)
{
	SetDOKey(OAxis_00, 2);
	SetDOKey(OAxis_01, 5);
	SetDOKey(OAxis_02, Address);
	SetDOKey(OAxis_03, Value ? 1 : 0);
	DOImmediate();
}

void UModbusDevice::WriteRegister(int Address, int Value)
{
	SetDOKey(OAxis_00, 2);
	SetDOKey(OAxis_01, 6);
	SetDOKey(OAxis_02, Address);
	SetDOKey(OAxis_03, Value);
	DOImmediate();
}