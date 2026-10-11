#pragma once
#include "Rendering/Renderer.hpp"
#include "Scene/Scene.hpp"
#include "Window.hpp"
#include "Input.hpp"
#include "Time.hpp"

enum class ENGINE_STATE{EDIT_MODE, PLAY_MODE};

class Engine {
public:
    Engine();
    void run();
    Scene scene;

private:
    void update();
    void render();
    void toggleState();

    ENGINE_STATE _currentState = ENGINE_STATE::EDIT_MODE;

    GameObject _editorCamera;
    Camera* _editorCameraComponent = nullptr;

    Window _window;
    Input _input;
    Time _time;
    bool _capturedMouse = true;
};