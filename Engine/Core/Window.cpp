#include "Window.hpp"
#include <iostream>

Window::Window() {
    init();
}
Window::~Window() {
    if (_win) glfwDestroyWindow(_win);
    glfwTerminate();
}

int Window::init() {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    _win = glfwCreateWindow(1600, 800, "NoviceEngine", NULL, NULL);

    if (!_win) {
        throw std::runtime_error("Failure during window creation");
    }

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

GLFWwindow* Window::getWindow() {return _win;}