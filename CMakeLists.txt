cmake_minimum_required(VERSION 3.20)
project(NoviceEngine)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

include(FetchContent)
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

add_executable(NoviceEngine
        includes/src/glad.c
        includes/tiny_obj_loader.h
        src/Mesh.hpp
        src/Mesh.cpp
        src/Window.hpp
        src/Window.cpp
        src/Shaders.hpp
        src/Shaders.cpp
        main.cpp
        utils/OBJLoader.cpp
)

target_include_directories(NoviceEngine PRIVATE includes)
target_link_libraries(NoviceEngine PRIVATE glfw OpenGL::GL)