// Fill out your copyright notice in the Description page of Project Settings.


#include "ModbusDevice.h"

void UModbusDevice::SwitchWriteCoilFuncCode()
{
	SetWriteFuncCode(5);
}

void UModbusDevice::SwitchWriteRegisterFuncCode()
{
	SetWriteFuncCode(6);
}

void UModbusDevice::WriteCoil(int Address, bool Value)
{
	SetDOKey(OAxis_240, 1);
	SetDOKey(OAxis_241, Address);
	SetDOKey(OAxis_242, Value);
	DOImmediate();
}

void UModbusDevice::WriteRegister(int Address, int Value)
{
	SetDOKey(OAxis_240, 2);
	SetDOKey(OAxis_241, Address);
	SetDOKey(OAxis_242, Value);
	DOImmediate();
}

void UModbusDevice::SetWriteFuncCode(int funCode)
{
	SetDOKey(OAxis_250, funCode);
}
