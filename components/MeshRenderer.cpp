#include "Transform.hpp"
#include "MeshRenderer.hpp"
#include "../src/Shaders.hpp"
#include "../src/GameObject.hpp"
#include "../utils/OBJLoader.hpp"

MeshRenderer::MeshRenderer(const std::string& path) {
    MeshData data = loadOBJ(path);
    mesh = std::make_unique<Mesh>(data.vertices,data.indices);
}

void MeshRenderer::render() {
    Transform* transform = parent->getComponent<Transform>();
    if (transform != nullptr) {
        glm::mat4 t = transform->getModelMatrix();
        Shaders::setMat4("u_modelMatrix", t);
    }
    mesh->draw();
}