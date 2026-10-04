#include "Renderer.hpp"
#include "Scene/GameObject.hpp"
#include "Components/MeshRenderer.hpp"

// TODO : Create material class for the future
#include "Assets/AssetManager.hpp"

#include <vector>

void Renderer::render(Scene& scene) {
    const std::vector<GameObject*> objects = scene.getGameObjects();

    for (auto* object : objects) {
        auto* meshRenderer = object->getComponent<MeshRenderer>();
        if (meshRenderer == nullptr)
            continue;

        auto* mesh = meshRenderer->getMesh();
        auto* shader = AssetManager::getShader("default");

        shader->bind();
        glBindVertexArray(mesh->getVAO());
        glDrawElements(GL_TRIANGLES,mesh->getIndexCount(),GL_UNSIGNED_INT,nullptr);
        glBindVertexArray(0);
        shader->unbind();
    }
}