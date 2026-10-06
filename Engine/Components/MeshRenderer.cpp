#include "MeshRenderer.hpp"

MeshRenderer::MeshRenderer(Mesh* mesh, Material* material): _mesh(mesh), _material(material) {}

Mesh* MeshRenderer::getMesh() const { return _mesh; }

Material* MeshRenderer::getMaterial() const { return _material; }