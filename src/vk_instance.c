#include "vk_instance.h"

#include <stdio.h>
#include <stdlib.h>

#include "vk_validation.h"
#include "definitions.h"

void createInstance(Vulkan* vulkan)
{
    if (ENABLE_VALIDATION_LAYERS && !checkValidationLayerSupport())
    {
        fprintf(stderr, "\n[ERROR] STATUS:FATAL |====> Validation Requested Not Available!");
        exit(EXIT_FAILURE);
    }

    printf("\n[LOG] STATUS:SUCCESS |====> Successfully Checked Validation!");

    VkApplicationInfo appInfo = {
        .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        .pApplicationName = vulkan->app_name,
        .applicationVersion = VK_MAKE_VERSION(vulkan->app_version[0],
                    vulkan->app_version[1],vulkan->app_version[2]),
        .pEngineName = "VLKC",
        .engineVersion = VK_MAKE_VERSION(1,0,0),
        .apiVersion = VK_API_VERSION_1_3,
        .pNext = NULL
    };

    uint32_t glfwExtensionCount = 0;
    const char ** glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
   
    VkInstanceCreateInfo createInfo = {
        .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        .pApplicationInfo = &appInfo,
        .enabledExtensionCount = glfwExtensionCount,
        .ppEnabledExtensionNames = glfwExtensions,
        .enabledLayerCount = 0
    };

    if (ENABLE_VALIDATION_LAYERS)
    {
        
        createInfo.enabledLayerCount = (uint32_t)(sizeof(validationLayers)/sizeof(validationLayers[0]));
        createInfo.ppEnabledLayerNames = validationLayers;
    } 
    else 
    {
        createInfo.enabledLayerCount = 0;
    }

    VkResult result = vkCreateInstance(&createInfo, NULL, &vulkan->instance);

    if (result != VK_SUCCESS)
    {
        fprintf(stderr, "\n[ERROR] STATUS:FATAL |====> Failed to create Instance!");
        exit(EXIT_FAILURE);
    }
}

void checkExtensionSupport()
{
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, NULL);
    VkExtensionProperties* extensions = malloc(extensionCount * (sizeof(VkExtensionProperties)));
    vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, extensions);

    printf("\n\n<=====> [LOG] STATUS:CHECK <=====>\n");

    printf("\n<===>| AVAILABLE EXTENSIONS LIST |<=====>");
    for (uint32_t i = 0; i < extensionCount; i++) {
        printf("\n<===| [EXTENSION]> %s", extensions[i].extensionName);
    }

    printf("\n\n<=====> [LOG] STATUS:CHECK <=====>\n");

    free(extensions);
}