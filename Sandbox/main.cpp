#include <iostream>
#include "../Engine/Core/Engine.hpp"
#include "../Engine/Components/MeshRenderer.hpp"

int main() {
    try {
        Engine engine;

        engine.run();

        auto* teapot = engine.scene.addGameObject<GameObject>();
        teapot->addComponent<MeshRenderer>(AssetManager::loadMesh("Assets/Models/utah_teapot.obj"));

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}