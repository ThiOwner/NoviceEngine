#pragma once

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

class Window {
public:
    Window() = default;

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    int init();

    void clear();

    void swapBuffers();

    void pollEvents();

    bool shouldClose();

    void terminate();

private:
    GLFWwindow* win = nullptr;
};