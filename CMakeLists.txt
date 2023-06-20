cmake_minimum_required(VERSION 3.25)
project(KMusicPP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_TOOLCHAIN_FILE "/Users/kyle/vcpkg/scripts/buildsystems/vcpkg.cmake")

if(DEFINED ENV{VCPKG_ROOT})
    get_filename_component(VCPKG_ROOT $ENV{VCPKG_ROOT} ABSOLUTE)
else()
    message(FATAL_ERROR "VCPKG_ROOT is not defined, please set the environment variable pointing to your vcpkg installation.")
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(dpp_DIR "${VCPKG_ROOT}/installed/x64-linux/share/dpp")
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    set(dpp_DIR "${VCPKG_ROOT}/installed/x64-osx/share/dpp")
else()
    message(FATAL_ERROR "Unsupported platform: ${CMAKE_SYSTEM_NAME}")
endif()

# Add DPP to CMake (via vcpkg)
find_package(dpp CONFIG REQUIRED)

# Include .cpp, do not include .h files. This won't cause any issues but its already in the .cpp and not common pratice.
add_executable(KMusicPP src/main.cpp src/env_loader.cpp)

# specify linking libraries after defining the target
target_link_libraries(KMusicPP PRIVATE dpp::dpp)
