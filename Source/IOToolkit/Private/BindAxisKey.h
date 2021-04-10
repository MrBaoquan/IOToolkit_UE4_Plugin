// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "BindAxisKey.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAxisKeyDelegatePin, float, AxisValue);
/**
 * 
 */
UCLASS()
class IOTOOLKIT_API UBindAxisKey : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintAssignable)
		FAxisKeyDelegatePin Update;

	UFUNCTION(BlueprintCallable,
		meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject",
			ToolTip = "订阅轴键事件",
			Category = "IOToolkit"
		)
	)
		static UBindAxisKey* IO_SubscribeAxisKey(const UObject* WorldContextObject,
			FString Device, FString AxisKey);

	virtual void Activate() override;

private:
	const UObject* WorldContextObject;
	bool Active;

	FString DeviceName;
	FString AxisKeyName;
	
};
