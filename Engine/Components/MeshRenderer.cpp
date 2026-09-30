#include "MeshRenderer.hpp"

#include "Transform.hpp"
#include "../Rendering/Shader.hpp"
#include "../Scene/GameObject.hpp"
#include "../Assets/OBJLoader.hpp"

MeshRenderer::MeshRenderer(const std::string& path, Shader* shader) {
    MeshData data = loadOBJ(path);
    mesh = std::make_unique<Mesh>(data.vertices,data.indices);
    this->shader = shader;
}

void MeshRenderer::render() {
    if (!isActive) {return;}
    shader->use();
    shader->setMat4("u_modelMatrix", parent->getTransform()->getModelMatrix());
    mesh->draw();
}