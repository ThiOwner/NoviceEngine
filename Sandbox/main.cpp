#include <iostream>
#include "../Engine/Core/Engine.hpp"
#include "../Engine/Components/MeshRenderer.hpp"

int main() {
    try {
        Engine engine;
        engine.run();

        auto* cube = engine.scene.addGameObject<GameObject>();
        cube->addComponent<MeshRenderer>(AssetManager::loadMesh("Assets/Models/cube.obj"));

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}