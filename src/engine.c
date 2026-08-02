#include "engine.h"
#include "resources.h"
#include "eng_vulkan.h"

#include <stdio.h>
#include <stdlib.h>

void start(EngineContext* eng_ctx)
{
    printf("\n[LOG] STATUS:START ==> Engine Started!");

    initWindow(&eng_ctx->window);
    initVulkan(&eng_ctx->vulkan);
    mainLoop(&eng_ctx->window);
    cleanUp(eng_ctx);

    printf("\n[LOG] STATUS:ENDED ==> Engine Stopped!");
}