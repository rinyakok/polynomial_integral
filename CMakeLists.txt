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