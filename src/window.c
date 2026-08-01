#include "window.h"

#include <stdio.h>
#include <stdlib.h>

int initWindow(Window* win) 
{
    if (glfwInit() == false)
    {
        fprintf(stderr, "Fatal: Failed to initialize GLFW!");
        return EXIT_FAILURE;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    win->window = glfwCreateWindow(win->width, win->height, win->title, nullptr, nullptr);

    return EXIT_SUCCESS;
}