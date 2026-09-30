#include "MeshRenderer.hpp"

#include "Transform.hpp"
#include "../src/Shader.hpp"
#include "../src/GameObject.hpp"
#include "../utils/OBJLoader.hpp"

MeshRenderer::MeshRenderer(const std::string& path, Shader* shader) {
    MeshData data = loadOBJ(path);
    mesh = std::make_unique<Mesh>(data.vertices,data.indices);
    this->shader = shader;
}

void MeshRenderer::render() {
    if (!isActive) {return;}
    Transform* transform = parent->getComponent<Transform>();
    shader->setMat4("u_modelMatrix", transform->getModelMatrix());
    shader->use();
    mesh->draw();
}