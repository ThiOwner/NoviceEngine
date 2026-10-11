#include "Renderer.hpp"
#include "Scene/GameObject.hpp"
#include "Components/MeshRenderer.hpp"
#include <vector>

void Renderer::render(const std::vector<MeshRenderer*>& renderers, const RenderView& view) {
    for (auto* meshRenderer : renderers) {
        Material* material = meshRenderer->getMaterial();
        Mesh*     mesh     = meshRenderer->getMesh();
        if (!material || !mesh) continue;

        material->bind();
        Shader* shader = material->getShader();

        shader->setMat4("u_projection", view.projection);
        shader->setMat4("u_view", view.view);
        shader->setVec3("u_lightDirection", view.lightDirection);
        shader->setVec3("u_dirLightColor", view.lightColor);
        shader->setFloat("u_dirLightIntensity", view.lightIntensity);
        shader->setMat4("u_model", meshRenderer->owner->getTransform()->getModelMatrix());

        glBindVertexArray(mesh->getVAO());
        glDrawElements(GL_TRIANGLES, mesh->getIndexCount(), GL_UNSIGNED_INT, nullptr);
        glBindVertexArray(0);

        material->unbind();
    }
}