#ifndef ENGINE_H
#define ENGINE_H

#include "engine_headers.h"

typedef struct {
    Window window;
} EngineContext;

int run(Window* win);

#endif