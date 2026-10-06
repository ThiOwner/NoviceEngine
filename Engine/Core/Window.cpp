#include "Window.hpp"
#include <iostream>
#include <stdexcept>

Window::Window(float width, float height) : _width(width), _height(height) { init(); }
Window::~Window() {
    if (_win) glfwDestroyWindow(_win);
    glfwTerminate();
}

int Window::init() {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    _win = glfwCreateWindow(static_cast<int>(_width), static_cast<int>(_height), "NoviceEngine", NULL, NULL);

    if (!_win) {
        throw std::runtime_error("Failure during window creation");
    }

    glfwSwapInterval(1);
    glfwMakeContextCurrent(_win);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failure during GLAD initialization");
    }

    // Enable depth calculations
    glEnable(GL_DEPTH_TEST);

    return 0;
}

void Window::clear() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::swapBuffers() { glfwSwapBuffers(_win); }

void Window::pollEvents() { glfwPollEvents(); }

bool Window::shouldClose() { return glfwWindowShouldClose(_win); }

GLFWwindow* Window::getWindow() { return _win; }

float Window::getAspectRatio() { return _width / _height; }

void Window::setCursorCaptured(bool captured) {
    glfwSetInputMode(_win, GLFW_CURSOR, captured ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
}

void Window::close() { glfwSetWindowShouldClose(_win, GLFW_TRUE); }