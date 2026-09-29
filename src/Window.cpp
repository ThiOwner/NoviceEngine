#include "Window.hpp"

int Window::init() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    win = glfwCreateWindow(1600, 800, "NoviceEngine", NULL, NULL);

    if (!win) {
        std::cerr << "Failure during window creation" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(win);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failure during GLAD initialization" << std::endl;
        return -1;
    }

    // Enable depth calculations
    glEnable(GL_DEPTH_TEST);

    return 0;
}

void Window::clear() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::swapBuffers() { glfwSwapBuffers(win); }

void Window::pollEvents() { glfwPollEvents(); }

bool Window::shouldClose() { return glfwWindowShouldClose(win); }

void Window::terminate() { glfwTerminate(); }
