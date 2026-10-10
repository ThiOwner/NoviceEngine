#include "Engine.hpp"

#include <imgui.h>
#include "Utils/FrameContext.hpp"
#include "Assets/AssetManager.hpp"

Engine::Engine(): _imgui(_window.getWindow()), _input(_window) {
    AssetManager::loadShader("default","Assets/Shaders/default.vert","Assets/Shaders/default.frag");
    _window.setCursorCaptured(true);
    _imgui.setMouseEnabled(false);
}

void Engine::run() {
    while (!_window.shouldClose()) {
        _window.pollEvents();
        _time.update();
        _input.update();

        _imgui.beginFrame();
        update();

        _window.clear();
        render();

        _imgui.drawDebugPanels(scene, ImGui::GetIO().Framerate, _time.getDeltaTime() * 1000.0f);
        _imgui.endFrame();

        _window.swapBuffers();
    }
    AssetManager::clear();
}

void Engine::update() {
    if (_input.isKeyJustPressed(Key::Escape)) _window.close();
    if (_input.isKeyJustPressed(Key::F1)) toggleUIMode();

    FrameContext context{ _time.getDeltaTime(), _time.getElapsedTime(), _input };
    scene.update(context);
}

void Engine::toggleUIMode() {
    _uiMode = !_uiMode;
    _window.setCursorCaptured(!_uiMode);
    _imgui.setMouseEnabled(_uiMode);
    _input.setEnabled(!_uiMode);
}

void Engine::render() {
    _renderer.render(scene,_window.getAspectRatio());
}