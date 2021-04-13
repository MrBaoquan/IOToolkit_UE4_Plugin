@echo off

set root_dir=%cd%\
set output_dir=%root_dir%Release\

setlocal EnableDelayedExpansion 

for /f "delims=" %%i in (Engines.txt) do (
    echo %%i
    rem %%i\RunUAT.bat BuildPlugin -Plugin=./IOToolkit.uplugin -Package=C:/Users/Administrator/Desktop/UE_Plugins/IOToolkit/4_26/IOToolkit -CreateSubFolder
    for /f "tokens=1,2* delims=|" %%i in ( "%%i" ) do (
        %%j\Engine\Build\BatchFiles\RunUAT.bat BuildPlugin -Plugin=%root_dir%IOToolkit.uplugin -Package=%output_dir%%%i -CreateSubFolder
    )
)