#include "Time.hpp"

#include "GLFW/glfw3.h"

Time::Time()
    : _lastTime(glfwGetTime()),
      _deltaTime(0.0),
      _elapsedTime(0.0) {}

void Time::update() {
    const double currentTime = glfwGetTime();
    _deltaTime = currentTime - _lastTime;
    _lastTime = currentTime;
    _elapsedTime += _deltaTime;
}

float Time::getDeltaTime() const {
    return static_cast<float>(_deltaTime);
}

float Time::getElapsedTime() const {
    return static_cast<float>(_elapsedTime);
}