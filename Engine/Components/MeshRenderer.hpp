#pragma once
#include "Component.hpp"
#include "Rendering/Mesh.hpp"

class MeshRenderer : public Component{
public:
    explicit MeshRenderer(Mesh* mesh);

    Mesh* getMesh() const;

private:
    Mesh* _mesh;
};