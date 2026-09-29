#pragma once

#include "Component.hpp"
#include "../src/Mesh.hpp"
#include <memory>

class MeshRenderer : public Component {
public:
    std::unique_ptr<Mesh> mesh;

    MeshRenderer(const std::string& path);

    void render() override;
};