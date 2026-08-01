#include "resources.h"

void cleanUp(EngineContext* eng_ctx)
{
    vkDestroyInstance(eng_ctx->vulkan.instance, NULL);
    
    glfwDestroyWindow(eng_ctx->window.window);
    glfwTerminate();
}