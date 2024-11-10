// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintAsyncActionBase.h"
#include "BindAxis.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAxisDelegatePin, float, AxisValue);

/**
 * 
 */
UCLASS()
class IOTOOLKIT_API UBindAxis : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintAssignable)
		FAxisDelegatePin Update;

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject",ToolTip = "订阅轴事件",Category = "IOToolkit"))
		static UBindAxis* IO_SubscribeAxis(const UObject* WorldContextObject, FString Device, FString Axis);

	virtual void Activate() override;
	
private:
	const UObject* WorldContextObject;
	bool Active;

	FString DeviceName;
	FString AxisName;
};
