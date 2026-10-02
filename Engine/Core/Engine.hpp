#pragma once
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
    Input input;
    Time time;
};