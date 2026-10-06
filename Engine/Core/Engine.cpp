#include "Engine.hpp"
#include "FrameContext.hpp"

Engine::Engine(): _window(),_input(_window){
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
    AssetManager::clear();
}

void Engine::update() {
    FrameContext context{ _time.getDeltaTime(), _time.getElapsedTime(), &_input };
    scene.update(context);
}

void Engine::render() {
    _renderer.render(scene,_window.getAspectRatio());
}