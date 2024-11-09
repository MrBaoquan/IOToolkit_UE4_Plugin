#pragma once

#include "CoreMinimal.h"
#include "IODevice.h"
#include "NetIODevice.generated.h"

UENUM(BlueprintType)
enum ENETIOEvent : uint8
{
    SetAll=0   UMETA(DisplayName = "Set All"),
    SetDI=1    UMETA(DisplayName = "Set DI"),
    SetAD=2    UMETA(DisplayName = "Set AD"),
    ZeroAll=10  UMETA(DisplayName = "Zero All"),
    ZeroDI=11   UMETA(DisplayName = "Zero DI"),
    ZeroAD=12   UMETA(DisplayName = "Zero AD")
};

UCLASS(Blueprintable)
class IOTOOLKIT_API UNetIODevice : public UIODevice
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "NetIO")
    void SetRemoteAddress(FString IP, int32 Port);

    UFUNCTION(BlueprintCallable, Category = "NetIO")
    void SetEventMode(TEnumAsByte<ENETIOEvent> Func);

    UFUNCTION(BlueprintCallable, Category = "NetIO")
    TEnumAsByte<ENETIOEvent> GetEventMode();

    UFUNCTION(BlueprintCallable, Category = "NetIO")
    void ZeroRemoteDI();

    UFUNCTION(BlueprintCallable, Category = "NetIO")
    void ZeroRemoteAD();

    UFUNCTION(BlueprintCallable, Category = "NetIO")
    void EmmitNetEvent(TEnumAsByte<EIO_ButtonKey::Type> chKey);

    UFUNCTION(BlueprintCallable, Category = "NetIO")
    void SetRemoteKeyDown(TEnumAsByte<EIO_ButtonKey::Type> Key);

    UFUNCTION(BlueprintCallable, Category = "NetIO")
    void SetRemoteKeyUp(TEnumAsByte<EIO_ButtonKey::Type> Key);

    UFUNCTION(BlueprintCallable, Category = "NetIO")
    void SetRemoteAxis(TEnumAsByte<EIO_AxisKey::Type> Key, float Value);

private:
    TEnumAsByte<EIO_OAxisKey> ChFunc = OAxis_240;
    TEnumAsByte<EIO_OAxisKey> ChPort = OAxis_245;
};
