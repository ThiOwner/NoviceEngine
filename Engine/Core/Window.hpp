#pragma once
#include "glad/glad.h"
#include <GLFW/glfw3.h>

class Window {
public:
    Window(float width = 1600, float height = 800);
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    void clear();
    void swapBuffers();
    void pollEvents();
    bool shouldClose();

    GLFWwindow* getWindow();

    float getAspectRatio();

    void setCursorCaptured(bool captured);

    void close();

private:
    GLFWwindow* _win = nullptr;

    float _width = 0.f, _height = 0.f;

    int init();
};