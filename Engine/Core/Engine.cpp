#include "Engine.hpp"

Engine::Engine(): window(),input(window){}

void Engine::run() {
    while (!window.shouldClose()) {
        window.pollEvents();

        time.update();
        input.update();

        window.clear();
        window.swapBuffers();
        window.pollEvents();
    }
}

void Engine::update() {
    // Not implemented yet
}

void Engine::render() {
    // Not implemented yet
}