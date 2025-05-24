@echo off
setlocal

if "%1"=="VS" (
    echo Generating Visual Studio configurations...
    rd /s /q "./build/debug"
    rd /s /q "./build/release"

    mkdir "./build/debug"
    mkdir "./build/release"

    echo Generating Debug Configuration...
    cmake -S . -B ./build/debug -G "Visual Studio 17 2022" -A x64 -DCMAKE_BUILD_TYPE=Debug
    echo Generating Release Configuration...
    cmake -S . -B ./build/release -G "Visual Studio 17 2022" -A x64 -DCMAKE_BUILD_TYPE=Release

) else if "%1"=="MinGW" (
    echo Generating MinGW configurations...
    rd /s /q "./build/debug"
    rd /s /q "./build/release"

    mkdir "./build/debug"
    mkdir "./build/release"

    echo Generating Debug Configuration...
    cmake -S . -B ./build/debug -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug
    echo Generating Release Configuration...
    cmake -S . -B ./build/release -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release

) else (
    echo Invalid parameter. Use "VS" for Visual Studio or "MinGW" for MinGW. (e.g., crt_makecfg.bat VS)
)

endlocal