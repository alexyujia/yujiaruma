cmake_minimum_required(VERSION 3.10)
project(Kernel CXX)

# Set Android-specific configurations
set(ANDROID_ABI "arm64-v8a")
set(ANDROID_PLATFORM "android-29") # As per requirement
set(ANDROID_STL "c++_shared")

# Set compiler flags for Android
set(CMAKE_CXX_FLAGS_INIT "-O2 -fPIC" CACHE STRING "Initial CXX flags")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_INIT} ${CMAKE_CXX_FLAGS}")


# Define output directories for libraries
# This helps in having a consistent output structure, especially for Android ABIs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${ANDROID_ABI})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${ANDROID_ABI})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${ANDROID_ABI})

# Add the shared library target
add_library(Kernel SHARED kernel.cpp)

# Set the output library name to "libKernel.so"
# By setting PREFIX to "", we prevent CMake from prepending "lib" again.
# OUTPUT_NAME is the full desired filename without "lib" prefix or ".so" suffix if PREFIX/SUFFIX are set.
# However, to be precise, it's often better to control prefix and suffix.
set_target_properties(Kernel PROPERTIES PREFIX "")
set_target_properties(Kernel PROPERTIES OUTPUT_NAME "libKernel")
# SUFFIX is already .so by default on Linux/Android for shared libraries.

message(STATUS "Project Name: ${CMAKE_PROJECT_NAME}")
message(STATUS "Android ABI: ${ANDROID_ABI}")
message(STATUS "Android Platform: ${ANDROID_PLATFORM}")
message(STATUS "Android STL: ${ANDROID_STL}")
message(STATUS "CXX Flags: ${CMAKE_CXX_FLAGS}")
message(STATUS "Library Output Directory: ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message(STATUS "Target Kernel output name: libKernel.so")
