#pragma once
#include "vulkan_context.hpp" // IWYU pragma: keep

#include <vector>

#ifdef NDEBUG
    #define ENABLE_VALIDATION_LAYERS 0
#else
    #define ENABLE_VALIDATION_LAYERS 1
#endif

extern const std::vector<const char*> validationLayers;
extern VkDebugUtilsMessengerEXT debugMessenger;

void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

void setupDebugMessenger(VkInstance instance);
void cleanupDebugMessenger(VkInstance instance);
