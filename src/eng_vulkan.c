#include "eng_vulkan.h"

#include <stdio.h>
#include <stdlib.h>

#include "vk_instance.h"

void initVulkan(Vulkan* vulkan)
{
    checkExtensionSupport();
    createInstance(vulkan);
    
    printf("\n[LOG] STATUS:SUCCESS |====> Succesfully Initialized Vulkan!");
}