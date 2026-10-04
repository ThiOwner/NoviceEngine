#include "Transform.hpp"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

Transform::Transform()
        : _position(0.0f, 0.0f, 0.0f),
          _rotation(0.0f, 0.0f, 0.0f),
          _scale(1.0f, 1.0f, 1.0f) {}

glm::mat4 Transform::getModelMatrix() const {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, _position);
    model = glm::rotate(model, glm::radians(_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, _scale);
    return model;
}

void Transform::setPosition(const glm::vec3& p) { _position = p; }
void Transform::setRotation(const glm::vec3& r) { _rotation = r; }
void Transform::setScale(const glm::vec3& s) { _scale = s; }

glm::vec3 Transform::getPosition() const { return _position; }
glm::vec3 Transform::getRotation() const { return _rotation; }
glm::vec3 Transform::getScale() const { return _scale; }

