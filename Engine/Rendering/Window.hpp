#pragma once

#include "./Include/glad/glad.h"
#include <GLFW/glfw3.h>

class Window {
public:
    Window();
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    void clear();

    void swapBuffers();

    void pollEvents();

    bool shouldClose();

private:
    GLFWwindow* win = nullptr;

    int init();
};