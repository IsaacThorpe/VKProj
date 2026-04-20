#pragma once

// Purpose of this header is to ensure that GLFW specifically includes the vulkan headers, then includes GLFW

// The "// IWYU pragma: keep" comment after #include vulkan_context.hpp is necessary because this header looks 
// unused but is just has degree of indirection which the IWYU analyzer doesn't detect

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>