// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintAsyncActionBase.h"
#include "BindAction.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActionDelegatePin, FString , KeyName);
/**
 * 
 */
UCLASS()
class IOTOOLKIT_API UBindAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:
		UPROPERTY(BlueprintAssignable)
			FActionDelegatePin IE_Pressed;

		UPROPERTY(BlueprintAssignable)
			FActionDelegatePin IE_Released;

		UFUNCTION(BlueprintCallable,
			meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"),
			Category = "IOToolkit")
			static UBindAction* IOSubscribeAction(const UObject* WorldContextObject,
				FString Device,
				FString Action);

		virtual void Activate() override;

private:
	const UObject* WorldContextObject;
	bool Active;

	FString DeviceName;
	FString ActionName;
};
