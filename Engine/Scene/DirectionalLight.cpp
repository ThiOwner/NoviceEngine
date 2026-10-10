#include "DirectionalLight.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

glm::vec3 DirectionalLight::getDirection() const {
    const float pitch = glm::radians(rotation.x);
    const float yaw = glm::radians(rotation.y);
    return glm::normalize(glm::vec3(
        std::cos(pitch) * std::sin(yaw),
        std::sin(pitch),
        std::cos(pitch) * std::cos(yaw)
    ));
}
