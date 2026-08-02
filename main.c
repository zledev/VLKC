#include <stdio.h>
#include <stdlib.h>

#include "engine.h"

int main() {
    char * app_name = "Vulkan World";

    EngineContext eng_ctx = {
        .window = {
            .window = NULL,
            .width = 800,
            .height = 600,
            .title = app_name
        },
        .vulkan = {
            .app_name = app_name
        }
    };
    
    start(&eng_ctx);
    
    return EXIT_SUCCESS;
}