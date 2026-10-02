#pragma once
#include "Window.hpp"

#include <array>

// Enums
enum class Key{ W,A,S,D,Space,Escape };
enum class MouseButton{ Left,Right,Middle };

class Input{
public:
    Input(Window& window);

    void update();

    bool isKeyPressed(Key key) const;
    bool isKeyJustPressed(Key key) const;
    bool isKeyJustReleased(Key key) const;

    bool isMouseButtonPressed(MouseButton button) const;

    //float getMouseX() const;
    //float getMouseY() const;
    //float getMouseDeltaX() const;
    //float getMouseDeltaY() const;

private:
    Window& window;

    std::array<bool, 512> currentKeys{};
    std::array<bool, 512> previousKeys{};

    static int keyToGLFWKey(Key key);
    static int mouseButtonToGLFWMouseButton(MouseButton button);
};