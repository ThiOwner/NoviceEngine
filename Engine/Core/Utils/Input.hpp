#pragma once
#include "../Window.hpp"

#include <array>

// Enums
enum class Key{ W,A,S,D,Space,Escape,LeftShift,F1 };
enum class MouseButton{ Left,Right,Middle };

class Input{
public:
    Input(Window& window);

    void update();

    bool isKeyPressed(Key key) const;
    bool isKeyPressedAnyState(Key key) const;
    bool isKeyJustPressed(Key key) const;
    bool isKeyJustReleased(Key key) const;

    bool isMouseButtonPressed(MouseButton button) const;

    float getMouseX() const;
    float getMouseY() const;
    float getMouseDeltaX() const;
    float getMouseDeltaY() const;

    void setEnabled(bool enabled);

private:
    Window& _window;

    bool _enabled = true;

    bool _firstMouse = true;
    double _mouseX = 0.0, _mouseY = 0.0, _mouseDeltaX = 0.0, _mouseDeltaY = 0.0;

    std::array<bool, GLFW_KEY_LAST + 1> _currentKeys{}, _previousKeys{};
    static int keyToGLFWKey(Key key);
    static int mouseButtonToGLFWMouseButton(MouseButton button);
};