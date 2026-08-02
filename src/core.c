#include "core.h"

#include <stdio.h>

void mainLoop(Window* win)
{
    printf("\n[LOG] STATUS:SUCCESS |====> Program Loop Started!");

    while(!glfwWindowShouldClose(win->window))
    {
        glfwPollEvents();
        break;
    }

    printf("\n[LOG] STATUS:SUCCESS |====> Program Loop Ended!");
}