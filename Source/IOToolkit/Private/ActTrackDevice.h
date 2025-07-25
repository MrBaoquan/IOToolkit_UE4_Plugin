// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IODevice.h"
#include "ActTrackDevice.generated.h"


UENUM(BlueprintType)
enum class EInputType : uint8
{
    Interact = 0 UMETA(DisplayName = "交互"),
    Button = 1 UMETA(DisplayName = "按钮"),
    Handle      UMETA(DisplayName = "手柄"),
    Joystick    UMETA(DisplayName = "摇杆"),
    MotorStart  UMETA(DisplayName = "电机启动"),
    Lever       UMETA(DisplayName = "拉杆"),
    Knob        UMETA(DisplayName = "旋钮"),
    Sensor      UMETA(DisplayName = "传感器"),
    Handwheel   UMETA(DisplayName = "手轮"),
    Camera      UMETA(DisplayName = "摄像头"),
    Radar       UMETA(DisplayName = "雷达"),
    Touch       UMETA(DisplayName = "触摸键"),
    Key         UMETA(DisplayName = "按键"),
    RFID        UMETA(DisplayName = "RFID"),
    Turntable   UMETA(DisplayName = "转盘"),
    Slider      UMETA(DisplayName = "滑杆"),
    Kinect      UMETA(DisplayName = "体感器"),
};

/**
 * 
 */
UCLASS()
class UActTrackDevice : public UIODevice
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "ActTrack")
	void NotifyStart();

	UFUNCTION(BlueprintCallable, Category = "ActTrack")
	void NotifyEnd();

	UFUNCTION(BlueprintCallable, Category = "ActTrack")
	void NotifyButton(int buttonID = 1);

	UFUNCTION(BlueprintCallable, Category = "ActTrack")
	void NotifyInput(TEnumAsByte<EInputType> inputType, int inputID);

    UFUNCTION(BlueprintCallable, Category = "ActTrack")
    void NotifyAlarm(int alarmID = 1);
};
