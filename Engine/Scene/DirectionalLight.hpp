#pragma once
#include "glm/vec3.hpp"

class DirectionalLight {
public:
    glm::vec3 rotation = glm::vec3(-45.0f, 30.0f, 0.5f);
    glm::vec3 color = glm::vec3(1.0f);
    float intensity = 1.5f;

    glm::vec3 getDirection() const;
};
