#include "NetIODevice.h"
#include "IODeviceController.h"
#include "IPAddress.h"
#include "Interfaces/IPv4/IPv4Address.h"
#include "SocketSubsystem.h"

namespace io = IOToolkit;

void UNetIODevice::SetRemoteAddress(FString IP, int32 Port)
{
	//bool bIsValid;
	FIPv4Address IPv4Address;
    if (!FIPv4Address::Parse(IP, IPv4Address)) {
        UE_LOG(LogTemp, Warning, TEXT("Invalid IP address: %s"), *IP);
        return;
    }

    SetDOKey(OAxis_241, IPv4Address.A);
    SetDOKey(OAxis_242, IPv4Address.B);
    SetDOKey(OAxis_243, IPv4Address.C);
    SetDOKey(OAxis_244, IPv4Address.D);

    
	SetDOKey(ChPort, Port);
}

void UNetIODevice::SetEventMode(TEnumAsByte<ENETIOEvent> Func)
{
    SetDOKey(ChFunc, (float)Func.GetValue());
}

TEnumAsByte<ENETIOEvent> UNetIODevice::GetEventMode()
{
    return static_cast<ENETIOEvent>((int32)GetDOKey(ChFunc));
}

void UNetIODevice::ZeroRemoteDI()
{
    SetEventMode(ENETIOEvent::ZeroDI);
    DOImmediate();
}

void UNetIODevice::ZeroRemoteAD()
{
    SetEventMode(ENETIOEvent::ZeroAD);
    DOImmediate();
}

void UNetIODevice::EmmitNetEvent(TEnumAsByte<EIO_ButtonKey::Type> chKey)
{
    
    SetEventMode(ENETIOEvent::SetDI);

    EIO_OAxisKey chOKey = static_cast<EIO_OAxisKey>(chKey.GetValue());
    SetDOKey(chOKey, 1);
    DOImmediate();
    SetDOKey(chOKey, 0);
    DOImmediate();
}

void UNetIODevice::SetRemoteKeyDown(TEnumAsByte<EIO_ButtonKey::Type> Key)
{
    SetEventMode(ENETIOEvent::SetDI);
    SetDOKey(static_cast<EIO_OAxisKey>(Key.GetValue()), 1);
    DOImmediate();
}

void UNetIODevice::SetRemoteKeyUp(TEnumAsByte<EIO_ButtonKey::Type> Key)
{
    SetEventMode(ENETIOEvent::SetDI);
    SetDOKey(static_cast<EIO_OAxisKey>(Key.GetValue()), 0);
    DOImmediate();

}

void UNetIODevice::SetRemoteAxis(TEnumAsByte<EIO_AxisKey::Type> Key, float Value)
{
    SetEventMode(ENETIOEvent::SetAD);
    SetDOKey(static_cast<EIO_OAxisKey>(Key.GetValue()), Value);
    DOImmediate();
}
