#pragma once
#include "Components/MeshRenderer.hpp"
#include <glm/glm.hpp>
#include <vector>

struct RenderView {
    glm::mat4 view;
    glm::mat4 projection;
    glm::vec3 lightDirection;
    glm::vec3 lightColor;
    float     lightIntensity;
};

class Renderer {
public:
    static void render(const std::vector<MeshRenderer*>& renderers, const RenderView& view);
};