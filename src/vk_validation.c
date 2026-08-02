#include "vk_validation.h"

#include <vulkan/vulkan.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool checkValidationLayerSupport()
{
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, NULL);

    VkLayerProperties* availableLayers = (VkLayerProperties*)malloc(layerCount * sizeof(VkLayerProperties));

    if (availableLayers == NULL)
    {
        free(availableLayers);
        fprintf(stderr, "\n[ERROR] STATUS:FATAL |====> Failed to allocate data: VkLayerProperties");
        exit(EXIT_FAILURE);
    }

    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers);

    printf("\n[LOG] STATUS:START |====> CHECKING VALIDATION LAYERS...\n");

    for (uint32_t i = 0; 
        i < (sizeof(validationLayers)/sizeof(validationLayers[0])); 
        i++)
    {
        bool layerFound = false;

        printf("\n[LOG] CHECK_VALIDATION [...] NAME |====> %s", validationLayers[i]);

        for (uint32_t j = 0; j < layerCount; j++)
        {
            if (strcmp(validationLayers[i], availableLayers[j].layerName))
            {
                printf("\n[LOG] STATUS:FOUND [✅] NAME |====> %s \n", validationLayers[i]);
                layerFound = true;
                break;
            }
        }

        if (!layerFound) {
            free(availableLayers);
            return false;
        }
    }

    printf("\n[LOG] STATUS:END |====> VALIDATION LAYERS CHECK FINISHED!\n");

    free(availableLayers);
    return true;
}