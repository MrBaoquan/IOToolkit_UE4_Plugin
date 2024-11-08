#include "NetIODevice.h"
#include "IOToolkit/include/IODeviceController.h"
#include "IPAddress.h"
#include "Interfaces/IPv4/IPv4Address.h"
#include "SocketSubsystem.h"

namespace io = IOToolkit;

void UNetIODevice::SetNetAddress(FString IP, int32 Port)
{
	//bool bIsValid;
	FIPv4Address IPv4Address;
    if (!FIPv4Address::Parse(IP, IPv4Address)) {
        UE_LOG(LogTemp, Warning, TEXT("Invalid IP address: %s"), *IP);
        return;
    }
    SetDO(FString::Printf(TEXT("OAxis_%d"), 241), IPv4Address.A, ESetDOType::OAxis);
    SetDO(FString::Printf(TEXT("OAxis_%d"), 242), IPv4Address.B, ESetDOType::OAxis);
    SetDO(FString::Printf(TEXT("OAxis_%d"), 243), IPv4Address.C, ESetDOType::OAxis);
    SetDO(FString::Printf(TEXT("OAxis_%d"), 244), IPv4Address.D, ESetDOType::OAxis);

	SetDO(ChPort, Port, ESetDOType::OAxis);
}

void UNetIODevice::SetEventMode(ENETIOEvent Func)
{
    SetDO(ChFunc, static_cast<int32>(Func), ESetDOType::OAxis);
}

ENETIOEvent UNetIODevice::GetEventMode()
{
    return static_cast<ENETIOEvent>(GetDO(ChFunc));
}

void UNetIODevice::ZeroDI()
{
    SetEventMode(ENETIOEvent::ZeroDI);
    DOImmediate();
}

void UNetIODevice::ZeroAD()
{
    SetEventMode(ENETIOEvent::ZeroAD);
    DOImmediate();
}

void UNetIODevice::EmmitNetEvent(int32 ChKey)
{
    EmmitNetEvent(FString::Printf(TEXT("OAxis_%02d"), ChKey));
}

void UNetIODevice::EmmitNetEvent(FString EvtKey)
{
    SetEventMode(ENETIOEvent::SetDI);
    SetDO(EvtKey, 1, ESetDOType::OAxis);
    DOImmediate();
    SetDO(EvtKey, 0, ESetDOType::OAxis);
    DOImmediate();
}

void UNetIODevice::SetButtonPressed(int32 Channel)
{
    FString Button = FString::Printf(TEXT("Button_%02d"), Channel);
    SetButtonPressed(Button);
}

void UNetIODevice::SetButtonPressed(FString Button)
{
    SetEventMode(ENETIOEvent::SetDI);
    SetDO(Button, 1, ESetDOType::OAxis);
    DOImmediate();
}

void UNetIODevice::SetButtonReleased(int32 Channel)
{
    FString Button = FString::Printf(TEXT("Button_%02d"), Channel);
    SetButtonReleased(Button);
}

void UNetIODevice::SetButtonReleased(FString Button)
{
    SetEventMode(ENETIOEvent::SetDI);
    SetDO(Button, 0, ESetDOType::OAxis);
    DOImmediate();
}

void UNetIODevice::SetAxis(int32 Channel, float Value)
{
    FString AxisKey = FString::Printf(TEXT("OAxis_%02d"), Channel);
    SetAxis(AxisKey, Value);
}

void UNetIODevice::SetAxis(FString AxisKey, float Value)
{
    SetEventMode(ENETIOEvent::SetAD);
    SetDO(AxisKey, Value, ESetDOType::OAxis);
    DOImmediate();
}
