#pragma once

#include <stdint.h>
#include <stdbool.h>

static const char* validationLayers[] = {
    "VK_LAYER_KHRONOS_validation",
};

bool checkValidationLayerSupport();