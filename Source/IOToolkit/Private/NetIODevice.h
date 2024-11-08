#pragma once

#include "CoreMinimal.h"
#include "IODevice.h"
#include "NetIODevice.generated.h"

UENUM(BlueprintType)
enum class ENETIOEvent : uint8
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
    void SetNetAddress(FString IP, int32 Port);

    UFUNCTION(BlueprintCallable, Category = "NetIO")
    void SetEventMode(TEnumAsByte<ENETIOEvent> Func);

    UFUNCTION(BlueprintCallable, Category = "NetIO")
    TEnumAsByte<ENETIOEvent> GetEventMode();

    UFUNCTION(BlueprintCallable, Category = "NetIO")
    void ZeroDI();

    UFUNCTION(BlueprintCallable, Category = "NetIO")
    void ZeroAD();

    UFUNCTION(BlueprintCallable, Category = "NetIO")
    void EmmitNetEvent(int32 ChKey);
    void EmmitNetEvent(FString EvtKey);

    UFUNCTION(BlueprintCallable, Category = "NetIO")
    void SetButtonPressed(int32 Channel);
    void SetButtonPressed(FString Button);

    UFUNCTION(BlueprintCallable, Category = "NetIO")
    void SetButtonReleased(int32 Channel);
    void SetButtonReleased(FString Button);

    UFUNCTION(BlueprintCallable, Category = "NetIO")
    void SetAxis(int32 Channel, float Value);
    void SetAxis(FString AxisKey, float Value);

private:
    FString ChFunc = TEXT("OAxis_240");
    FString ChPort = TEXT("OAxis_245");
};
