@echo off

set root_dir=%cd%\
set output_dir=%root_dir%Release\

set version=2.3.1

setlocal EnableDelayedExpansion 

for /f "delims=" %%i in (Engines.txt) do (
    rem %%i\RunUAT.bat BuildPlugin -Plugin=./IOToolkit.uplugin -Package=C:/Users/Administrator/Desktop/UE_Plugins/IOToolkit/4_26/IOToolkit -CreateSubFolder
    for /f "tokens=1,2* delims=|" %%i in ( "%%i" ) do (
        echo "================== Build for %%i =================="
        %%j\Engine\Build\BatchFiles\RunUAT.bat BuildPlugin -Plugin=%root_dir%IOToolkit.uplugin -Package=%output_dir%%version%\%%i -CreateSubFolder
    )
)