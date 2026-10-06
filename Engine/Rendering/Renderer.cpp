#include "Renderer.hpp"
#include "Scene/GameObject.hpp"
#include "Components/MeshRenderer.hpp"
#include <vector>

void Renderer::render(Scene& scene, float aspectRatio) {
    const std::vector<GameObject*> objects = scene.getGameObjects();

    const Camera* activeCamera = scene.getActiveCamera();
    const glm::mat4 viewMatrix = activeCamera->getViewMatrix();
    const glm::mat4 projectionMatrix = activeCamera->getProjectionMatrix(aspectRatio);

    for (auto* object : objects) {
        auto* meshRenderer = object->getComponent<MeshRenderer>();
        if (meshRenderer == nullptr)
            continue;

        auto* material = meshRenderer->getMaterial();
        material->bind();
        auto* shader = material->getShader();

        shader->setMat4("u_projection", projectionMatrix);
        shader->setMat4("u_view", viewMatrix);

        auto* mesh = meshRenderer->getMesh();
        glm::mat4 modelMatrix = object->getTransform()->getModelMatrix();
        shader->setMat4("u_model", modelMatrix);

        glBindVertexArray(mesh->getVAO());
        glDrawElements(GL_TRIANGLES,mesh->getIndexCount(),GL_UNSIGNED_INT,nullptr);
        glBindVertexArray(0);

        material->unbind();
    }
}