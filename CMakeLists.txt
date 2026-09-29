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

FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 1.0.1
)
FetchContent_MakeAvailable(glm)

file(GLOB_RECURSE SOURCES
        "src/**.cpp"
        "src/**.hpp"
        "utils/**.cpp"
        "utils/**.hpp"
        "components/**.cpp"
        "components/**.hpp"
        "includes/src/*.c"
        "includes/*.h"
        "main.cpp"
)

add_executable(NoviceEngine ${SOURCES})

target_include_directories(NoviceEngine PRIVATE includes)
target_link_libraries(NoviceEngine PRIVATE glfw glm::glm OpenGL::GL)