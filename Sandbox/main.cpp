#include <iostream>
#include "../Engine/Core/Engine.hpp"
#include "Components/FreeCamera.hpp"
#include "../Engine/Components/Camera.hpp"
#include "../Engine/Rendering/Material.hpp"
#include "../Engine/Assets/AssetManager.hpp"
#include "../Engine/Components/MeshRenderer.hpp"

int main() {
    try {
        Engine engine;

        auto* camera = engine.scene.addGameObject<GameObject>();
        auto* cameraComponent = camera->addComponent<Camera>(45.0f,0.1f,1000.0f);
        camera->getTransform()->setPosition(glm::vec3(0.0f, 0.0f, -2.0f));
        camera->addComponent<FreeCamera>();

        engine.scene.setActiveCamera(cameraComponent);

        Material defaultMaterial(AssetManager::getShader("default"));

        auto* teapot = engine.scene.addGameObject<GameObject>();
        teapot->addComponent<MeshRenderer>(AssetManager::loadMesh("Assets/Models/utah_teapot.obj"),&defaultMaterial);
        teapot->getTransform()->setPosition(glm::vec3(0.0f,-1.0f,10.0f));
        teapot->getTransform()->setScale(glm::vec3(1.0f));

        engine.run();

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
