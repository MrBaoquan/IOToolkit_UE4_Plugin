// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "IODevice.h"
#include "IOToolkit_BPF.generated.h"


/**
 * 
 */
UCLASS()
class IOTOOLKIT_API UIOToolkit_BPF : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	DECLARE_DYNAMIC_DELEGATE(FActionDelegate);
	DECLARE_DYNAMIC_DELEGATE_OneParam(FActionDelegateWithKey, FString, KeyName);
	DECLARE_DYNAMIC_DELEGATE_OneParam(FAxisDelegate, float, AxisValue);

		UFUNCTION(BlueprintCallable, meta = (Keywords = "IOToolkit",ToolTip="加载 IO设备"), Category = "IOToolkit")
			static void IO_Load();

		UFUNCTION(BlueprintCallable, meta = (Keywords = "IOToolkit",ToolTip = "IO 逻辑帧循环"), Category = "IOToolkit")
			static void IO_Update();

		UFUNCTION(BlueprintCallable, meta = (Keywords = "IOToolkit",ToolTip = "IO 卸载设备"), Category = "IOToolkit")
			static void IO_Unload();

		UFUNCTION(BlueprintCallable, meta = (Keywords = "IOToolkit",ToolTip = "IO 清除事件绑定"), Category = "IOToolkit")
			static void IO_ClearBindings();

		UFUNCTION(BlueprintCallable, meta = (Keywords="IOToolkit",ToolTip = "获取IO设备"),Category="IOToolkit")
			static UIODevice* IO_GetDevice(FString DeviceName);
			
		UFUNCTION(BlueprintCallable, meta = (Keywords = "IOToolkit",ToolTip = "IO 立即执行输出"), Category = "IOToolkit")
			static int32 IO_DOImmediate(FString Device);

		UFUNCTION(BlueprintCallable, meta = (Keywords = "IOToolkit",ToolTip = "IO 设置输出"), Category = "IOToolkit")
			static void IO_SetDO(FString Device, FString Name, float Value);

		UFUNCTION(BlueprintCallable, meta = (Keywords = "IOToolkit",ToolTip = "IO 设置输出"), Category = "IOToolkit")
			static void IO_SetDOKey(FString Device, TEnumAsByte<EIO_OAxisKey> Key, float Value);

		UFUNCTION(BlueprintCallable, meta = (Keywords = "IOToolkit",ToolTip = "IO 设置输出"), Category = "IOToolkit")
			static void IO_SetDOKey_S(FString Device, FString Key, float Value);

		UFUNCTION(BlueprintCallable, meta = (Keywords = "IOToolkit",ToolTip = "IO 设置输出 开"), Category = "IOToolkit")
			static void IO_SetDOOn(FString Device, FString OAction);

		UFUNCTION(BlueprintCallable, meta = (Keywords = "IOToolkit",ToolTip = "IO 设置输出 关"), Category = "IOToolkit")
			static void IO_SetDOOff(FString Device, FString OAction);

		UFUNCTION(BlueprintCallable, meta = (Keywords = "IOToolkit",ToolTip = "IO 获取输出"), Category = "IOToolkit")
			static float IO_GetDO(FString Device, FString Name);

		UFUNCTION(BlueprintCallable, meta = (Keywords = "IOToolkit",ToolTip = "IO 获取输出"), Category = "IOToolkit")
			static float IO_GetDOKey(FString Device, TEnumAsByte<EIO_OAxisKey> Key);

		UFUNCTION(BlueprintCallable, meta = (Keywords = "IOToolkit",ToolTip = "IO 获取输出"), Category = "IOToolkit")
			static float IO_GetDOKey_S(FString Device, FString Key);
		
		UFUNCTION(BlueprintCallable, meta = (Keywords = "IOToolkit",ToolTip = "IO 获取按键状态"), Category = "IOToolkit")
			static bool IO_GetKey(FString Device, FString Key);

		UFUNCTION(BlueprintCallable, meta = (Keywords = "IOToolkit",ToolTip = "IO 按键由释放状态被按下时, 返回一帧true"), Category = "IOToolkit")
			static bool IO_GetKeyDown(FString Device, FString Key);

		UFUNCTION(BlueprintCallable, meta = (Keywords = "IOToolkit",ToolTip = "获取按键被按下的时长"), Category = "IOToolkit")
			static float IO_GetKeyDownDuration(FString Device, FString Key);

		UFUNCTION(BlueprintCallable, meta = (Keywords = "IOToolkit",ToolTip = "IO 按键由按下状态被释放时, 返回一帧true"), Category = "IOToolkit")
			static bool IO_GetKeyUp(FString Device, FString Key);

		UFUNCTION(BlueprintCallable, meta = (Keywords = "IOToolkit",ToolTip = "IO 获取设备指定Axis结点经过计算后的值"), Category = "IOToolkit")
			static float IO_GetAxis(FString Device, FString Name);

		UFUNCTION(BlueprintCallable, meta = (Keywords = "IOToolkit",ToolTip = "IO 获取设备指定AxisKey的值"), Category = "IOToolkit")
			static float IO_GetAxisKey(FString Device, FString Key);

};
