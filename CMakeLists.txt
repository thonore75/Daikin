cmake_minimum_required(VERSION 3.15)

project(Daikin)

# Find GTest library
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "Use shared (DLL) run-time lib even when Google Test is built as static lib" FORCE)
FetchContent_MakeAvailable(googletest)

# Set source and test directories
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(TEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tests")

# Add source files to target
file(GLOB SOURCE_FILES "${SOURCE_DIR}/*.cpp")
add_library(TemperatureControllerLib ${SOURCE_FILES})

# Include directories
target_include_directories(TemperatureControllerLib PUBLIC "${SOURCE_DIR}")

# Add test files to target
file(GLOB TEST_FILES "${TEST_DIR}/*.cpp")
add_executable(TemperatureControllerTests ${TEST_FILES})
target_link_libraries(TemperatureControllerTests PRIVATE TemperatureControllerLib gtest_main gmock)

# Include directories for tests
target_include_directories(TemperatureControllerTests PRIVATE "${TEST_DIR}")
target_include_directories(TemperatureControllerTests PRIVATE "${SOURCE_DIR}")

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
