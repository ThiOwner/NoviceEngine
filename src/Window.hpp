#pragma once

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

class Window {
public:
    Window();
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    int init();

    void clear();

    void swapBuffers();

    void pollEvents();

    bool shouldClose();

private:
    GLFWwindow* win = nullptr;
};