#include <stdio.h>
#include <stdlib.h>

#include "engine.h"

int main() {
    EngineContext eng_ctx = {
        .window = {
            .window = nullptr,
            .width = 800,
            .height = 600,
            .title = "Vulkan World"
        }
    };
    
    return run(&eng_ctx.window);;
}