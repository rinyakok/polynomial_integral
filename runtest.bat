@echo off
setlocal

if "%1"=="" (
    echo Warning: No parameter provided. Default will be used: "release".
    set "TEST_TYPE=release"
) else (
    set "TEST_TYPE=%1"
)

if "%TEST_TYPE%"=="release" (
    echo Running ctest for release configuration...
    if not exist "./build/release" (
        echo Error: Release build directory does not exist. Please run crt_makecfg.bat first.
        exit /b 1
    )

    cd "./build/release"  
) else if "%TEST_TYPE%"=="debug" (
    echo Running ctest for debug configuration...
    if not exist "./build/debug" (
        echo Error: Debug build directory does not exist. Please run crt_makecfg.bat first.
        exit /b 1
    )

    cd "./build/debug" 
) else (
    echo Error: Requested test configuration not supported.
    exit /b 1
)

ctest -V --output-on-failure

if %errorlevel% neq 0 (
    echo Error: ctest failed with error code %errorlevel%.
    cd ../..
    exit /b %errorlevel%
)

cd ../..

endlocal