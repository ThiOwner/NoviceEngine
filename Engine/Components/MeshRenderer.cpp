#include "MeshRenderer.hpp"

#include "Transform.hpp"
#include "../Rendering/Shader.hpp"
#include "../Scene/GameObject.hpp"
#include "../Assets/OBJLoader.hpp"
#include "../Engine/Assets/AssetManager.hpp"

MeshRenderer::MeshRenderer(const std::string& path, Shader* shader) {
    this->mesh = std::make_unique<Mesh>(AssetManager::loadMesh(path));
    this->shader = shader;
}

void MeshRenderer::render() {
    if (!isActive) {return;}
    shader->use();
    shader->setMat4("u_modelMatrix", parent->getTransform()->getModelMatrix());
    mesh->draw();
}