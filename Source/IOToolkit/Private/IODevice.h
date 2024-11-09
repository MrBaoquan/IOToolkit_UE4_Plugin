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
        void ClearBingings();

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
        int32 DOImmediate();

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
        void SetDO(FString Name, float Value);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
        void SetDOKey(TEnumAsByte<EIO_OAxisKey> Key, float Value);
    
    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
        void SetDOKey_S(FString Key, float Value);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
        float GetDO(FString Name);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
        float GetDOKey(TEnumAsByte<EIO_OAxisKey> Key);
    
    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
        float GetDOKey_S(FString Key);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
        void SetDOOn(FString OAction);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
        void SetDOOff(FString OAction);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
        bool GetKey(FString Key);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
        bool GetKeyDown(FString Key);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
        float GetKeyDownDuration(FString Key);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
        bool GetKeyUp(FString Key);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
        float GetAxis(FString InAxis);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
        float GetAxisKey(FString AxisKey);

    UFUNCTION(BlueprintCallable, Category = "IOToolkit")
        void PropagateDIEvents(UNetIODevice* NetIODevice, int32 StartChannel, int32 Count);

    UFUNCTION(BlueprintCallable, Category="IOToolkit")
        void BindKey(TEnumAsByte<EIO_Key> Key, TEnumAsByte<EIOEvent::Type> EventType, FActionDelegate InCallback);

    UFUNCTION(BlueprintCallable, Category="IOToolkit")
        void BindKey_S(FString Key, TEnumAsByte<EIOEvent::Type> EventType, FActionDelegate InCallback);

    UFUNCTION(BlueprintCallable, Category="IOToolkit")
        void BindAction(FString InAction, TEnumAsByte<EIOEvent::Type> EventType, FActionDelegateWithKey InCallback);

    UFUNCTION(BlueprintCallable, Category="IOToolkit")
        void BindAxisKey(TEnumAsByte<EIO_Key> Key, FAxisDelegate InCallback);

    UFUNCTION(BlueprintCallable, Category="IOToolkit")
        void BindAxisKey_S(FString Key, FAxisDelegate InCallback);

    UFUNCTION(BlueprintCallable, Category="IOToolkit")
        void BindAxis(FString Name, FAxisDelegate InCallback);

    UPROPERTY(BlueprintReadOnly, Category="IOToolkit")
    FString DeviceName;
protected:
    UIODevice();
    ~UIODevice();
    
};
