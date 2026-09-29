#include "MeshRenderer.hpp"
#include "../utils/OBJLoader.hpp"

MeshRenderer::MeshRenderer(const std::string& path) {
    MeshData data = loadOBJ(path);
    mesh = std::make_unique<Mesh>(data.vertices,data.indices);
}

void MeshRenderer::render() {
    mesh->draw();
}