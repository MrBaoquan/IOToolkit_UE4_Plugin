#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IOToolkit.h"
#include "IODevice.generated.h"

UCLASS(Blueprintable)
class IOTOOLKIT_API UIODevice : public UObject
{
    GENERATED_BODY()

public:

    DECLARE_DYNAMIC_DELEGATE(FActionDelegate);
    DECLARE_DYNAMIC_DELEGATE_OneParam(FActionDelegateWithKey, FString, KeyName);
    DECLARE_DYNAMIC_DELEGATE_OneParam(FAxisDelegate, float, AxisValue);

    static TMap<FString, UIODevice*> DeviceMap;
    static UIODevice* GetOrCreateIODevice(FString Name);
    static void ClearIODevices();

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
    void Initialize(FString Name);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
    int32 DOImmediate();

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
    void SetDO(FString Target, float Value, TEnumAsByte<ESetDOType::Type> Type = ESetDOType::OAction);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
    float GetDO(FString Target, TEnumAsByte<ESetDOType::Type> Type = ESetDOType::OAction);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
    void SetDOOn(FString OAction);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
    void SetDOOff(FString OAction);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
    bool GetKey(FString InKey);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
    bool GetKeyDown(FString InKey);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
    float GetKeyDownDuration(FString InKey);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
    bool GetKeyUp(FString InKey);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
    float GetAxis(FString InAxis);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
    float GetAxisKey(FString InAxisKey);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
    void PropagateDIEvents(UNetIODevice* NetIODevice, int32 StartChannel, int32 Count);

    UFUNCTION(BlueprintCallable, Category="IOToolkit")
    void BindKey(FString InKey, TEnumAsByte<EIOEvent::Type> EventType, FActionDelegate InCallback);

    UFUNCTION(BlueprintCallable, Category="IOToolkit")
    void BindAction(FString InAction, TEnumAsByte<EIOEvent::Type> EventType, FActionDelegateWithKey InCallback);

    UFUNCTION(BlueprintCallable, Category="IOToolkit")
    void BindAxisKey(FString InAxisKey, FAxisDelegate InCallback);

    UFUNCTION(BlueprintCallable, Category="IOToolkit")
    void BindAxis(FString InAction, FAxisDelegate InCallback);

    FString DeviceName;
protected:
    UIODevice();
    ~UIODevice();
    
};
