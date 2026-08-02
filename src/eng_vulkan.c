#include "eng_vulkan.h"

#include <stdio.h>
#include <stdlib.h>

void createInstance(Vulkan* vulkan)
{
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

    VkResult result = vkCreateInstance(&createInfo, NULL, &vulkan->instance);

    if (result != VK_SUCCESS)
    {
        fprintf(stderr, "\n[ERROR] STATUS:FATAL ==> Failed to create Instance!");
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

    for (uint32_t i = 0; i < extensionCount; i++) {
        printf("\n[EXTENSION]> %s", extensions[i].extensionName);
    }

    printf("\n\n<=====> [LOG] STATUS:CHECK <=====>\n");

    free(extensions);
}

void initVulkan(Vulkan* vulkan)
{
    checkExtensionSupport();
    createInstance(vulkan);
    
    printf("\n[LOG] STATUS:SUCCESS ==> Succesfully Initialized Vulkan!");
}