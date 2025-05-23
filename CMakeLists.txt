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

#===================================== Build Type =====================================
# Set default build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type (default Release)" FORCE)
endif()

# Optionally, add configuration-specific compile options
target_compile_definitions(IntegratorLib PRIVATE 
    $<$<CONFIG:Debug>:DEBUG_BUILD>
    $<$<CONFIG:Release>:NDEBUG>
)
#=======================================================================================

#=================================== Compile Options ===================================

# Set compiler options and warnings for IntegratorLib
target_compile_options(IntegratorLib PRIVATE
    # Release options
    $<$<CONFIG:Release>:
        $<$<CXX_COMPILER_ID:MSVC>:/O2>  # Highest optimization#
        $<$<CXX_COMPILER_ID:GNU>:-O3>   #
    >
    # Debug options
    $<$<CONFIG:Debug>:
        $<$<CXX_COMPILER_ID:MSVC>:/Od /Zi>  # No optimization, debug info
        $<$<CXX_COMPILER_ID:GNU>:-O0 -g>    # No optimization, debug info
    >
    # Warnings (applied to all configs)
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic>
)

# Set linker options for IntegratorLib
target_link_options(IntegratorLib PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/LTCG> #  Link Time Code Generation
    $<$<CXX_COMPILER_ID:GNU>:-flto> # Link Time Optimization
)

#=======================================================================================

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

