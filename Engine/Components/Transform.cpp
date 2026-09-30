#include "Transform.hpp"

void Transform::setPosition(glm::vec3 p) {
    position = p;
    computeModelMatrix();
}

void Transform::setRotation(glm::vec3 r) {
    this->rotation = r;
    computeModelMatrix();
}

void Transform::setScale(glm::vec3 s) {
    this->scale = s;
    computeModelMatrix();
}

glm::mat4 Transform::getModelMatrix() {
    return modelMatrix;
}

void Transform::computeModelMatrix() {
    modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::translate(modelMatrix, position);
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    modelMatrix = glm::scale(modelMatrix, scale);
}
