#pragma once
#include "../Scene/Scene.hpp"
#include "Window.hpp"
#include "Input.hpp"
#include "Time.hpp"

class Engine {
public:
    Engine();

    void run();

private:
    void update();
    void render();

    Window window;
    Scene scene;
    Input input;
    Time time;
};