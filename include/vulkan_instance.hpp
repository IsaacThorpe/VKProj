#pragma once 
#include "vulkan_context.hpp" // IWYU pragma: keep

extern VkInstance instance;

void initVulkan();
void cleanupVulkan();
