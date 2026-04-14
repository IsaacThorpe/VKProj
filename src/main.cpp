#include "vulkan_context.hpp" // THIS FIRST

#include <iostream>
#include <cstdlib>

#include "vulkan_instance.hpp"
#include "window.hpp"

void mainLoop();
void cleanup();

int main() {
    try {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

// ----------------------------------------------------- //

void mainLoop() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

void cleanup() {
    cleanupVulkan();
    cleanupWindow();
}

