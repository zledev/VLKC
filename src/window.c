#include "window.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initWindow(Window* win) 
{
    if (glfwInit() == false)
    {
        fprintf(stderr, "\n[ERROR] STATUS:Fatal ==> Failed to initialize GLFW!");
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    win->window = glfwCreateWindow(win->width, win->height, win->title, NULL, NULL);
    
    printf("\n[LOG] STATUS:SUCCESS ==> Successfully Initialized Window!");
}