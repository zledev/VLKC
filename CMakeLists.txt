cmake_minimum_required(VERSION 3.28)
project(vulkan_engine LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra)

set(CMAKE_BUILD_TYPE Release) 

file(GLOB_RECURSE SRC_FILES "main.c" "src/*.c")

add_executable(vulkan_engine ${SRC_FILES})

target_include_directories(vulkan_engine PRIVATE include)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(vulkan_engine PRIVATE
    Vulkan::Vulkan
    glfw
    cglm
    GL
    m
)
