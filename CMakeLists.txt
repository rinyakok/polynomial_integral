cmake_minimum_required(VERSION 3.10)
project(Integrator LANGUAGES CXX)

# Collect all .cpp files from Module directory and subdirectories
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Integrator/*.cpp")

# Create static library from all sources
add_library(IntegratorLib STATIC ${SOURCES})

# Include directories for both targets
target_include_directories(IntegratorLib PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/integrator/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/ETL/include/
)

# Set C++ standard for both targets
set_target_properties(IntegratorLib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
)

#=================================================== Unit Tests =========================================================

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

message(STATUS "gtest_SOURCE_DIR = ${gtest_SOURCE_DIR}")

enable_testing()

file(GLOB_RECURSE TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp")

add_executable(IntegratorUnitTests ${TEST_SOURCES})

target_include_directories(IntegratorUnitTests PRIVATE 
    ${gtest_SOURCE_DIR}/include
    $<TARGET_PROPERTY:IntegratorLib,INCLUDE_DIRECTORIES>
)

target_link_libraries(IntegratorUnitTests
    PRIVATE
        IntegratorLib
        gtest
        gtest_main
)

add_test(NAME IntegratorUnitTests COMMAND IntegratorUnitTests)

