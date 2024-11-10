// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "IOTypes.h"
#include "BindKey.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FKeyDelegatePin);
/**
 * 
 */
UCLASS()
class IOTOOLKIT_API UBindKey : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintAssignable)
		FKeyDelegatePin IE_Pressed;

	UPROPERTY(BlueprintAssignable)
		FKeyDelegatePin IE_Released;

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject",ToolTip = "订阅按键事件"),Category = "IOToolkit")
		static UBindKey* IO_SubscribeKey(const UObject* WorldContextObject,FString Device, TEnumAsByte<EIO_Key> Key);

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject",ToolTip = "订阅按键事件"),Category = "IOToolkit")
		static UBindKey* IO_SubscribeKey_S(const UObject* WorldContextObject,FString Device,FString Key);

	virtual void Activate() override;

private:
	const UObject* WorldContextObject;
	bool Active;

	FString DeviceName;
	TEnumAsByte<EIO_Key> Key;
	FString KeyString;
};
