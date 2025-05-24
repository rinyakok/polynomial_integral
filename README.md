# Polynomial Integrator Library

## Overview

This project provides a C++ static library, **libIntegratorLib**, for polynomial integration.
The project includes CMake configuration and unit test environment based on GoogleTest.

Code using ETL (Embedded template Library).

---

## 1. How to integrate `libIntegratorLib` to your project

To use `libIntegratorLib` in your own project:

1. **Copy library binary & include files to your project**
   - copy libIntegratorLib.a (or libIntegratorLib.lib depending on your compiler) from ./build/output/lib/debug or release folder to your project
   - copy files from ./build/output/include/ to your project include folder
   - code using ETL (Embedded template Library). Please make sure it's added/included into your project.

3. **How to use library function**
   - include integrator.h to your source file. (Note: integrator.tpp shall be in the same folder as integrator.h)
   - call integratePolynomial with parameters:
  ```c++
  /// Calculates the approximate solution for integral of the polynomial function with numerical integration
  ∫ 𝑓(𝑥)𝑑𝑥 , where 𝑓(𝑥) = 𝑎0 + 𝑎1𝑥 + 𝑎2𝑥2+. . . +𝑎𝑛−1𝑥𝑛−1 + 𝑎𝑛𝑥𝑛
  /// @param coeffs Coefficients of the integrand polynomial function, given coeffs[𝑖] = 𝑎𝑖
  /// @param lowerLimit Lower boundary for the integration 𝑎
  /// @param upperLimit Upper boundary for the integration 𝑏
  /// @return Approximate solution to the definite integral of the polynomial function
  
  float integratePolynomial(const etl::array<float, n>& coeffs, const float lowerLimit, const float upperLimit)
  ```
  - update your linker configuration to link integrator library to your project, and reference include directories (both: integrator & etl)
  (e.g. reference in your CMakeLists.txt)
   ```cmake
   add_subdirectory(external/integrator)
   target_link_libraries(YourTarget PRIVATE IntegratorLib)
   target_include_directories(YourTarget PRIVATE
       ${CMAKE_CURRENT_SOURCE_DIR}/external/integrator/integrator/include
       ${CMAKE_CURRENT_SOURCE_DIR}/external/integrator/ETL/include
   )
   ```

3. **Build your project**  
   
---

## 2. Modify / rebuild library

The project's make configuration is built with CMake and tested on windows by using MinGW C++ compiler.
If you need recompile or modify the project on your side, please consider the followings:
  - CMakeLists.txt configuration prepared for supporting Microsoft Visual Studio C++ Compiler (msvc) and GNU (g++) compilers at the moment.
  - In order to be able to build this project locally on your PC, you need to regenerate CMake configuration.
    (For this, you need to have MSVC or g++ compiler & CMake installed on your computer

For Make configuration regeneration you may use the crt_makecfg.bat with **VS** or **MinGW** parameter.
e.g.:
```sh
crt_makecfg.bat MinGW
```

This script will clean and reconfigure the CMake build environment.

---

## 3. Building the Polynomial Integrator Project

To build the project (including the library and unit tests), use build.bat with parameter **release** or **debug**.
e.g.:
```sh
build.bat release
```

This will invoke CMake and your compiler toolchain to build library & unit test targets in the appropriate configuration (default is Release).

---

## 4. Running the Tests

To run the unit tests after building, use: runtest.bat with parameter  **release** or **debug**.

```sh
runtest.bat release
```

This will execute all tests and report the results in the console.

---

## License

See [LICENSE](LICENSE) for details.
