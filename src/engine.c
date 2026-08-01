#include "engine.h"

#include <stdlib.h>

int run(Window* win)
{
    if (initWindow(win) == EXIT_FAILURE)
    return EXIT_FAILURE;
    
    // initVulkan
    mainLoop(win);
    cleanUp(win);

    return EXIT_SUCCESS;
}