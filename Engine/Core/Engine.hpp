#pragma once
#include "Rendering/Renderer.hpp"
#include "Scene/Scene.hpp"
#include "Window.hpp"
#include "Utils/Input.hpp"
#include "Utils/Time.hpp"
#include "UI/ImGuiLayer.hpp"

class Engine {
public:
    Engine();

    void run();

    Scene scene;
private:
    void update();
    void render();
    void toggleUIMode();

    Renderer _renderer;
    Window _window;
    ImGuiLayer _imgui;
    Input _input;
    Time _time;

    bool _uiMode = false;
};