#include "MeshRenderer.hpp"

#include "Transform.hpp"
#include "../src/Shaders.hpp"
#include "../src/GameObject.hpp"
#include "../utils/OBJLoader.hpp"

MeshRenderer::MeshRenderer(const std::string& path, Shaders* shader) {
    MeshData data = loadOBJ(path);
    mesh = std::make_unique<Mesh>(data.vertices,data.indices);
    this->shader = shader;
}

void MeshRenderer::render() {
    if (!isActive) {return;}
    Transform* transform = parent->getComponent<Transform>();
    if (transform != nullptr) {
        glm::mat4 t = transform->getModelMatrix();
        shader->setMat4("u_modelMatrix", t);
    }
    mesh->draw();
}