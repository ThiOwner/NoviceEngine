#include "Camera.hpp"
#include "Scene/GameObject.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <cassert>

Camera::Camera(float fov, float near, float far) : _fov(fov), _near(near), _far(far) {}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(
        owner->getTransform()->getPosition()+cameraOffset.getPosition(),
        owner->getTransform()->getPosition(),
        _upVector
    );
}

glm::mat4 Camera::getProjectionMatrix(float aspectRatio) const {
    return glm::perspective(
        glm::radians(_fov),
        aspectRatio,
        _near,
        _far
    );
}
