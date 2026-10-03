#include <iostream>
#include "../Engine/Core/Engine.hpp"

int main() {
    try {
        Engine engine;
        engine.run();

        auto* test = engine.scene.addGameObject<GameObject>();

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}