#include "resources.h"

#include <stdio.h>

void cleanUp(EngineContext* eng_ctx)
{
    vkDestroyInstance(eng_ctx->vulkan.instance, NULL);
    
    glfwDestroyWindow(eng_ctx->window.window);
    glfwTerminate();

    printf("\n[LOG] STATUS:SUCCESS |====> Successfully Cleaned Up Resources!");
}