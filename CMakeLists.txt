cmake_minimum_required(VERSION 3.15)

project(VKProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---- Default build type ----
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

file(GLOB_RECURSE SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(VKProject ${SRC_FILES})

target_include_directories(VKProject PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# ---- Dependencies ----
add_subdirectory(external/glfw)

find_package(Vulkan REQUIRED)

target_link_libraries(VKProject
    PRIVATE
        glfw
        Vulkan::Vulkan
)

# ---- Platform-specific settings ----
if(WIN32)
    target_compile_definitions(VKProject PRIVATE VK_USE_PLATFORM_WIN32_KHR)

    # Optional: avoid console window for GUI apps
    # set_target_properties(VKProject PROPERTIES WIN32_EXECUTABLE TRUE)

elseif(UNIX)
    # ---- Dependencies ----
    find_package(Threads REQUIRED)

    target_link_libraries(VKProject 
        PRIVATE 
            Threads::Threads
            dl 
            X11 
            Xxf86vm 
            Xrandr 
            Xi 
        )
endif()

# ---- Debug / Release macros ----
target_compile_definitions(VKProject PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
    $<$<CONFIG:Release>:NDEBUG>
)