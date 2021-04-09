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
	
		UFUNCTION(BlueprintCallable, meta = (Keywords = "BP_Template sample test testing"), Category = "IOToolkit")
			static void IO_Load();

		UFUNCTION(BlueprintCallable, meta = (Keywords = "BP_Template sample test testing"), Category = "IOToolkit")
			static void IO_Update();

		UFUNCTION(BlueprintCallable, meta = (Keywords = "BP_Template sample test testing"), Category = "IOToolkit")
			static void IO_Unload();

		UFUNCTION(BlueprintCallable, meta = (Keywords = "BP_Template sample test testing"), Category = "IOToolkit")
			static void IO_ClearBindings();



};
