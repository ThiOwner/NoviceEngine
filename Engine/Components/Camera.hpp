#pragma once
#include "Transform.hpp"
#include "glm/mat4x4.hpp"


class Camera : public Component {
public:
    Camera(float fov, float near, float far);

    glm::mat4 getViewMatrix() const;
    glm::mat4 getProjectionMatrix(float aspectRatio) const;

    Transform cameraOffset;

private:
    float _fov;
    float _near;
    float _far;

    glm::vec3 _upVector = glm::vec3(0.0f, 1.0f, 0.0f);
};
