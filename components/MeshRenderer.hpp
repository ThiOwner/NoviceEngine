#pragma once

#include "Component.hpp"
#include "../src/Mesh.hpp"
#include <memory>

class Shaders;

class MeshRenderer : public Component {
public:
    std::unique_ptr<Mesh> mesh;
    Shaders* shader;

    MeshRenderer(const std::string& path, Shaders* shader);

    void render() override;
};