#include "Engine.hpp"

Engine::Engine(): _window(),_input(_window){
    // Compiling shaders
    AssetManager::loadShader("default","Assets/Shaders/default.vert","Assets/Shaders/default.frag");
}

void Engine::run() {
    while (!_window.shouldClose()) {
        _window.pollEvents();

        _time.update();
        _input.update();

        update();

        _window.clear();
        render();

        _window.swapBuffers();
    }
}

void Engine::update() {
    scene.update(_time.getDeltaTime());
}

void Engine::render() {
    _renderer.render(scene,_window.getAspectRatio());
}