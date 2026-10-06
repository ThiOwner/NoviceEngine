#pragma once
#include "Component.hpp"
#include "Rendering/Mesh.hpp"
#include "Rendering/Material.hpp"

class MeshRenderer : public Component{
public:
    explicit MeshRenderer(Mesh* mesh, Material* material);

    Mesh* getMesh() const;

    Material* getMaterial() const;

private:
    Mesh* _mesh;
    Material* _material;
};