#include "Time.hpp"

#include "GLFW/glfw3.h"

Time::Time()
    : lastTime(glfwGetTime()),
      deltaTime(0.0),
      elapsedTime(0.0) {}

void Time::update() {
    const double currentTime = glfwGetTime();
    deltaTime = currentTime - lastTime;
    lastTime = currentTime;
    elapsedTime += deltaTime;
}

float Time::getDeltaTime() const {
    return static_cast<float>(deltaTime);
}

float Time::getElapsedTime() const {
    return static_cast<float>(elapsedTime);
}