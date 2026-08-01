#include "core.h"

void mainLoop(Window* win)
{
    while(!glfwWindowShouldClose(win->window))
    {
        glfwPollEvents();
    }
}