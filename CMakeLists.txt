cmake_minimum_required(VERSION 3.20)

project(
        NoviceEngine
        VERSION 0.1.0
        DESCRIPTION "C++ Game Engine"
        LANGUAGES CXX C
)

# ============================================================
# Global configuration
# ============================================================

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ============================================================
# Dependencies
# ============================================================

find_package(OpenGL REQUIRED)

include(FetchContent)

# ------------------------------------------------------------
# GLFW
# ------------------------------------------------------------

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
)

FetchContent_MakeAvailable(glfw)

# ------------------------------------------------------------
# GLM
# ------------------------------------------------------------

FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 1.0.1
)

FetchContent_MakeAvailable(glm)

# ============================================================
# GLAD
# ============================================================

add_library(glad STATIC
        Engine/Include/src/glad.c
)

target_include_directories(
        glad
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Engine/Include
)

# ============================================================
# NoviceEngine
# ============================================================

set(ENGINE_SOURCES

        # ----------------------------------------------------
        # Core
        # ----------------------------------------------------

        Engine/Core/Engine.cpp
        Engine/Core/Window.cpp
        Engine/Core/Input.cpp
        Engine/Core/Time.cpp

        # ----------------------------------------------------
        # Scene
        # ----------------------------------------------------

        Engine/Scene/Scene.cpp
        Engine/Scene/GameObject.cpp
        Engine/Scene/DirectionalLight.cpp

        # ----------------------------------------------------
        # Components
        # ----------------------------------------------------

        Engine/Components/Camera.cpp
        Engine/Components/Transform.cpp
        Engine/Components/MeshRenderer.cpp
        Engine/Components/FreeCamera.cpp

        # ----------------------------------------------------
        # Rendering
        # ----------------------------------------------------

        Engine/Rendering/Mesh.cpp
        Engine/Rendering/Shader.cpp
        Engine/Rendering/Material.cpp
        Engine/Rendering/Renderer.cpp

        # ----------------------------------------------------
        # Assets
        # ----------------------------------------------------

        Engine/Assets/AssetManager.cpp
        Engine/Assets/OBJLoader.cpp
)

set(ENGINE_HEADERS

        # ----------------------------------------------------
        # Core
        # ----------------------------------------------------

        Engine/Core/Engine.hpp
        Engine/Core/Window.hpp
        Engine/Core/Input.hpp
        Engine/Core/Time.hpp
        Engine/Core/Types.hpp
        Engine/Core/FrameContext.hpp

        # ----------------------------------------------------
        # Scene
        # ----------------------------------------------------

        Engine/Scene/Scene.hpp
        Engine/Scene/GameObject.hpp
        Engine/Scene/DirectionalLight.hpp

        # ----------------------------------------------------
        # Components
        # ----------------------------------------------------

        Engine/Components/Camera.hpp
        Engine/Components/Component.hpp
        Engine/Components/Transform.hpp
        Engine/Components/MeshRenderer.hpp
        Engine/Components/FreeCamera.hpp

        # ----------------------------------------------------
        # Rendering
        # ----------------------------------------------------

        Engine/Rendering/Mesh.hpp
        Engine/Rendering/Shader.hpp
        Engine/Rendering/Material.hpp
        Engine/Rendering/Renderer.hpp

        # ----------------------------------------------------
        # Assets
        # ----------------------------------------------------

        Engine/Assets/OBJLoader.hpp
        Engine/Assets/AssetManager.hpp
)

add_library(
        NoviceEngine
        STATIC
        ${ENGINE_SOURCES}
        ${ENGINE_HEADERS}
)

target_include_directories(
        NoviceEngine
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Engine
)

target_link_libraries(
        NoviceEngine
        PUBLIC
        glfw
        glm::glm
        OpenGL::GL
        glad
)

target_compile_features(
        NoviceEngine
        PUBLIC
        cxx_std_17
)

# ============================================================
# Sandbox
# ============================================================

add_executable(
        NoviceSandbox
        Sandbox/main.cpp
)

target_link_libraries(
        NoviceSandbox
        PRIVATE
        NoviceEngine
)

# ============================================================
# Compiler warnings
# ============================================================

if (MSVC)

    target_compile_options(
            NoviceEngine
            PRIVATE
            /W4
            /permissive-
    )

    target_compile_options(
            NoviceSandbox
            PRIVATE
            /W4
            /permissive-
    )

else()

    target_compile_options(
            NoviceEngine
            PRIVATE
            -Wall
            -Wextra
            -Wpedantic
    )

    target_compile_options(
            NoviceSandbox
            PRIVATE
            -Wall
            -Wextra
            -Wpedantic
    )

endif()

# ============================================================
# Output directories
# ============================================================

set_target_properties(
        NoviceEngine
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY
        ${CMAKE_BINARY_DIR}/lib
)

set_target_properties(
        NoviceSandbox
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY
        ${CMAKE_BINARY_DIR}/bin
)
