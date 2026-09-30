#pragma once

#include "Component.hpp"
#include "../Rendering/Mesh.hpp"
#include <memory>

class Shader;

class MeshRenderer : public Component {
public:
    std::unique_ptr<Mesh> mesh;
    Shader* shader;

    MeshRenderer(const std::string& path, Shader* shader);

    void render() override;
};