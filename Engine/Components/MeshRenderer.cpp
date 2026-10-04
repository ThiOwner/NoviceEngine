#include "MeshRenderer.hpp"

MeshRenderer::MeshRenderer(Mesh* mesh): _mesh(mesh) {}

Mesh* MeshRenderer::getMesh() const { return _mesh; }