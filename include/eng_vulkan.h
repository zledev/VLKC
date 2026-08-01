#ifndef ENG_VULKAN_H
#define ENG_VULKAN_H

#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

typedef struct {
    char* app_name;
    int app_version[3];
    VkInstance instance;
} Vulkan;

void initVulkan(Vulkan* vulkan);

#endif