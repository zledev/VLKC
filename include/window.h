#ifndef WINDOW_H
#define WINDOW_H

#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

typedef struct {
    GLFWwindow * window;
    const char * title;
    uint32_t width;
    uint32_t height;
} Window;

void initWindow(Window* win);

#endif