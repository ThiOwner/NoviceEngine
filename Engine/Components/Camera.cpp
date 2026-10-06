#include "Camera.hpp"
#include "Scene/GameObject.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <cassert>

Camera::Camera(float fov, float near, float far) : _fov(fov), _near(near), _far(far) {}

glm::mat4 Camera::getViewMatrix() const {
    const Transform* t = owner->getTransform();
    const glm::vec3 pos = t->getPosition();
    const glm::vec3 rot = t->getRotation();
    return glm::lookAt(pos, pos + forwardFromAngles(rot.x, rot.y), _upVector);
}

glm::mat4 Camera::getProjectionMatrix(float aspectRatio) const {
    return glm::perspective(
        glm::radians(_fov),
        aspectRatio,
        _near,
        _far
    );
}

glm::vec3 Camera::forwardFromAngles(float pitchDeg, float yawDeg) {
    const float pitch = glm::radians(pitchDeg);
    const float yaw = glm::radians(yawDeg);
    return glm::normalize(glm::vec3(
        std::cos(pitch) * std::sin(yaw),
        std::sin(pitch),
        std::cos(pitch) * std::cos(yaw)
    ));
}
