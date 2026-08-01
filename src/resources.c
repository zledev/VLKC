#include "resources.h"

void cleanUp(Window* win)
{
    glfwDestroyWindow(win->window);
    glfwTerminate();
}