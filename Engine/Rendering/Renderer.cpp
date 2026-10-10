#include "Renderer.hpp"
#include "Scene/GameObject.hpp"
#include "Components/MeshRenderer.hpp"
#include <vector>

void Renderer::render(Scene& scene, float aspectRatio) {
    const std::vector<GameObject*> objects = scene.getGameObjects();

    const Camera* activeCamera = scene.getActiveCamera();
    const glm::mat4 viewMatrix = activeCamera->getViewMatrix();
    const glm::mat4 projectionMatrix = activeCamera->getProjectionMatrix(aspectRatio);

    const glm::vec3 gLightDirection = scene.dirLight.getDirection();
    const glm::vec3 lightDirView = glm::normalize(glm::mat3(viewMatrix) * -gLightDirection);
    const glm::vec3 gDirLightColor = scene.dirLight.color;
    const float gDirLightIntensity = scene.dirLight.intensity;

    for (auto* object : objects) {
        auto* meshRenderer = object->getComponent<MeshRenderer>();
        if (meshRenderer == nullptr)
            continue;

        auto* material = meshRenderer->getMaterial();
        material->bind();
        auto* shader = material->getShader();

        shader->setMat4("u_projection", projectionMatrix);
        shader->setMat4("u_view", viewMatrix);

        shader->setVec3("u_lightDirection", lightDirView);
        shader->setVec3("u_dirLightColor", gDirLightColor);
        shader->setFloat("u_dirLightIntensity", gDirLightIntensity);

        auto* mesh = meshRenderer->getMesh();
        glm::mat4 modelMatrix = object->getTransform()->getModelMatrix();
        shader->setMat4("u_model", modelMatrix);

        glBindVertexArray(mesh->getVAO());
        glDrawElements(GL_TRIANGLES,mesh->getIndexCount(),GL_UNSIGNED_INT,nullptr);
        glBindVertexArray(0);

        material->unbind();
    }
}