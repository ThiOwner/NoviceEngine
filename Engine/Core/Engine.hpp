#pragma once
#include "Scene/Scene.hpp"
#include "Window.hpp"
#include "Input.hpp"
#include "Time.hpp"

class Engine {
public:
    Engine();

    void run();

    Scene scene;
private:
    void update();
    void render();

    Window window;
    Input input;
    Time time;
};