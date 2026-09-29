#pragma once
#include "Component.hpp"
#include "glm/fwd.hpp"
#include "glm/vec3.hpp"
#include <glm/gtc/matrix_transform.hpp>

class Transform : public Component {
public:
    glm::mat4 modelMatrix = glm::mat4(1.0f);
    glm::vec3 position = glm::vec3(0.0f);
    glm::vec3 rotation = glm::vec3(0.0f);
    glm::vec3 scale = glm::vec3(1.0f);

    void setPosition(glm::vec3 position);
    void setRotation(glm::vec3 rotation);
    void setScale(glm::vec3 scale);

    glm::mat4 getModelMatrix();

    void computeModelMatrix();
};
