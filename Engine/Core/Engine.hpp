#pragma once
#include "Assets/AssetManager.hpp"
#include "Rendering/Renderer.hpp"
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

    Renderer _renderer;
    Window _window;
    Input _input;
    Time _time;
};