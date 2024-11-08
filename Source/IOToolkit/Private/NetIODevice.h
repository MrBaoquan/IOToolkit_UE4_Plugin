#pragma once

#include "CoreMinimal.h"
#include "IODevice.h"
#include "NetIODevice.generated.h"

UENUM(BlueprintType)
enum class ENETIOEvent : uint8
{
    SetAll   UMETA(DisplayName = "Set All"),
    SetDI    UMETA(DisplayName = "Set DI"),
    SetAD    UMETA(DisplayName = "Set AD"),
    ZeroAll  UMETA(DisplayName = "Zero All"),
    ZeroDI   UMETA(DisplayName = "Zero DI"),
    ZeroAD   UMETA(DisplayName = "Zero AD")
};

UCLASS(Blueprintable)
class IOTOOLKIT_API UNetIODevice : public UIODevice
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "NetIO")
    void SetNetAddress(FString IP, int32 Port);

    UFUNCTION(BlueprintCallable, Category = "NetIO")
    void SetEventMode(ENETIOEvent Func);

    UFUNCTION(BlueprintCallable, Category = "NetIO")
    ENETIOEvent GetEventMode();

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
