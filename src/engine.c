#include "engine.h"
#include "resources.h"
#include "eng_vulkan.h"

#include <stdlib.h>

int start(EngineContext* eng_ctx)
{
    if (initWindow(&eng_ctx->window) == EXIT_FAILURE)
    return EXIT_FAILURE;
    
    initVulkan(&eng_ctx->vulkan);
    mainLoop(&eng_ctx->window);
    cleanUp(eng_ctx);

    return EXIT_SUCCESS;
}