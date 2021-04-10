// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "IOToolkit_BPF.generated.h"

/**
 * 
 */
UCLASS()
class IOTOOLKIT_API UIOToolkit_BPF : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
		UFUNCTION(BlueprintCallable, meta = (
			Keywords = "IOToolkit",
			ToolTip="加载 IO设备"
		), Category = "IOToolkit")
			static void IO_Load();

		UFUNCTION(BlueprintCallable, meta = (
			Keywords = "IOToolkit",
			ToolTip = "IO 逻辑帧循环"
		), Category = "IOToolkit")
			static void IO_Update();

		UFUNCTION(BlueprintCallable, meta = (
			Keywords = "IOToolkit",
			ToolTip = "IO 卸载设备"
		), Category = "IOToolkit")
			static void IO_Unload();

		UFUNCTION(BlueprintCallable, meta = (
			Keywords = "IOToolkit",
			ToolTip = "IO 清除事件绑定"
		), Category = "IOToolkit")
			static void IO_ClearBindings();

		UFUNCTION(BlueprintCallable, meta = (
			Keywords = "IOToolkit",
			ToolTip = "IO 设置输出"
		), Category = "IOToolkit")
			static void IO_SetDO(FString Device, FString Target, float Value, TEnumAsByte<ESetDOType> Type = ESetDOType::OAction);

		UFUNCTION(BlueprintCallable, meta = (
			Keywords = "IOToolkit",
			ToolTip = "IO 设置输出 开"
			), Category = "IOToolkit")
			static void IO_SetDOOn(FString Device, FString OAction);

		UFUNCTION(BlueprintCallable, meta = (
			Keywords = "IOToolkit",
			ToolTip = "IO 设置输出 关"
			), Category = "IOToolkit")
			static void IO_SetDOOff(FString Device, FString OAction);

};
