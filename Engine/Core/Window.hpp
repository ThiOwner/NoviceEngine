#pragma once
#include "glad/glad.h"
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

    GLFWwindow* getWindow();

private:
    GLFWwindow* win = nullptr;

    int init();
};