# CMake Version
cmake_minimum_required(VERSION 3.15)

# Project Name
project(VulkanEngine)

# C++ Version (C++ 17)
set(CMAKE_CXX_STANDARD 17)

# Debug Build
SET(CMAKE_BUILD_TYPE Debug)

# Compile Codes
add_executable(VulkanEngine main.cpp common.hpp src/app.hpp src/app.cpp vulkan/core.hpp vulkan/core.cpp vulkan/debug.hpp vulkan/debug.cpp src/window.hpp src/window.cpp)

# Library link
# Vulkan
find_package(Vulkan REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_LIBRARIES})
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)

# PkgConfig
find_package(PkgConfig REQUIRED)
pkg_search_module(GLM REQUIRED glm)
include_directories(${GLM_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GLM_LIBRARY_DIRS})

# GLFW
find_package(glfw3)
target_link_libraries(${PROJECT_NAME} glfw)