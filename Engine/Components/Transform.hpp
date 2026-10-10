#pragma once
#include "Component.hpp"
#include "glm/mat4x4.hpp"
#include "glm/vec3.hpp"

class Transform {
public:
    Transform();

    glm::mat4 getModelMatrix() const;

    void setPosition(const glm::vec3& p);
    void setRotation(const glm::vec3& r);
    void setScale(const glm::vec3& s);

    glm::vec3 getPosition() const;
    glm::vec3 getRotation() const;
    glm::vec3 getScale() const;

private:
    glm::vec3 _position, _rotation, _scale;
};
