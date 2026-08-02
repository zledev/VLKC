#ifndef ENGINE_H
#define ENGINE_H

#pragma once

#include "core.h"
#include "eng_vulkan.h"

typedef struct EngineContext {
    Window window;
    Vulkan vulkan;
} EngineContext;

void start(EngineContext * eng_ctx);

#endif