#include "Input.hpp"
#include "GLFW\glfw3.h"

Input::Input(Window& window): window(window){}

void Input::update() {
    previousKeys = currentKeys;
    for (int key = 0; key < 512; ++key){
        currentKeys[key] = glfwGetKey(window.getWindow(), key) == GLFW_PRESS;
    }
}

bool Input::isKeyPressed(const Key key) const {
    const int glfwKey = keyToGLFWKey(key);
    return currentKeys[glfwKey];
}

bool Input::isKeyJustPressed(const Key key) const {
    const int glfwKey = keyToGLFWKey(key);
    return currentKeys[glfwKey]&&!previousKeys[glfwKey];
}

bool Input::isKeyJustReleased(const Key key) const {
    const int glfwKey = keyToGLFWKey(key);
    return !currentKeys[glfwKey]&&previousKeys[glfwKey];
}

bool Input::isMouseButtonPressed(MouseButton button) const {
    return glfwGetMouseButton(window.getWindow(), mouseButtonToGLFWMouseButton(button)) == GLFW_PRESS;
}

// Static methods
int Input::keyToGLFWKey(const Key key) {
    switch (key) {
        case Key::W: return GLFW_KEY_W;
        case Key::S: return GLFW_KEY_S;
        case Key::A: return GLFW_KEY_A;
        case Key::D: return GLFW_KEY_D;
        case Key::Escape: return GLFW_KEY_ESCAPE;
        case Key::Space: return GLFW_KEY_SPACE;
        default: return GLFW_KEY_UNKNOWN;
    }
}

int Input::mouseButtonToGLFWMouseButton(const MouseButton button) {
    switch (button) {
        case MouseButton::Left: return GLFW_MOUSE_BUTTON_LEFT;
        case MouseButton::Right: return GLFW_MOUSE_BUTTON_RIGHT;
        case MouseButton::Middle: return GLFW_MOUSE_BUTTON_MIDDLE;
        default: return -1;
    }
}

