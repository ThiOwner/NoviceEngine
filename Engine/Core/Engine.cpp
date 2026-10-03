#include "Engine.hpp"

Engine::Engine(): window(),input(window){}

void Engine::run() {
    while (!window.shouldClose()) {
        window.pollEvents();

        time.update();
        input.update();

        update();

        window.clear();
        render();

        window.swapBuffers();
    }
}

void Engine::update() {
    scene.update(time.getDeltaTime());
}

void Engine::render() {
    // Not implemented yet
}