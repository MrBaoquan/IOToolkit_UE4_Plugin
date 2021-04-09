// Fill out your copyright notice in the Description page of Project Settings.

#include "IOToolkit_BPF.h"
#include "IOToolkit.h"
#include "IODeviceController.h"
namespace io = IOToolkit;

void UIOToolkit_BPF::IO_Load()
{
	IO_ClearBindings();
	io::IODeviceController::Instance().Load();
}

void UIOToolkit_BPF::IO_Update()
{
	io::IODeviceController::Instance().Update();
}

void UIOToolkit_BPF::IO_Unload()
{
	io::IODeviceController::Instance().Unload();
}

void UIOToolkit_BPF::IO_ClearBindings()
{
	io::IODeviceController::Instance().ClearBindings();
}
