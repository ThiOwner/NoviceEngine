#include "FreeCamera.hpp"
#include "Camera.hpp"
#include "Scene/GameObject.hpp"
#include "Core/Input.hpp"
#include <glm/glm.hpp>

void FreeCamera::update(const FrameContext& context) {
    Transform* transform = owner->getTransform();
    const Input& input = context.input;

    glm::vec3 rot = transform->getRotation();
    rot.y -= input.getMouseDeltaX() * mouseSensitivity;
    rot.x -= input.getMouseDeltaY() * mouseSensitivity;
    rot.x = glm::clamp(rot.x, -89.0f, 89.0f);
    transform->setRotation(rot);

    const glm::vec3 up(0.0f, 1.0f, 0.0f);
    const glm::vec3 forward = Camera::forwardFromAngles(rot.x, rot.y);
    const glm::vec3 right = glm::normalize(glm::cross(forward, up));

    glm::vec3 dir(0.0f);
    if (input.isKeyPressed(Key::W)) dir += forward;
    if (input.isKeyPressed(Key::S)) dir -= forward;
    if (input.isKeyPressed(Key::D)) dir += right;
    if (input.isKeyPressed(Key::A)) dir -= right;
    if (input.isKeyPressed(Key::Space)) dir += up;
    if (input.isKeyPressed(Key::LeftShift)) dir -= up;

    if (glm::length(dir) > 0.0f) {
        transform->setPosition(transform->getPosition() + glm::normalize(dir) * moveSpeed * context.deltaTime);
    }
}