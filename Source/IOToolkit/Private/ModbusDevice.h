// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IODevice.h"
#include "ModbusDevice.generated.h"

/**
 * 
 */
UCLASS()
class UModbusDevice : public UIODevice
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable, Category = "Modbus")
		void SetSlaveID(int Address);

	UFUNCTION(BlueprintCallable, Category = "Modbus")
		void WriteCoil(int Address, bool Value);

	UFUNCTION(BlueprintCallable, Category = "Modbus")
		void WriteRegister(int Address, int Value);

};
