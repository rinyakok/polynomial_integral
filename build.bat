@echo off
setlocal

if "%1"=="" (
    echo Warning: No parameter provided. Default will be used: "release".
    set "BUILD_TYPE=release"
) else (
    set "BUILD_TYPE=%1"
)

if "%BUILD_TYPE%"=="release" (
    echo Building Release configuration...
    cmake --build "./build/release" --config Release
) else if "%BUILD_TYPE%"=="debug" (
    echo Building Debug configuration...
    cmake --build "./build/debug" --config Debug
) else (
    echo Error: Requested build configuration not supported.
    exit /b 1
)

endlocal