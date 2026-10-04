#include "Renderer.hpp"
#include "Scene/GameObject.hpp"
#include "Components/Component.hpp"
#include <vector>

void Renderer::render(Scene& scene) {
    std::vector<GameObject*> objects = scene.getGameObjects();
    for (auto* object : objects) {
        // Not implemented yet.
    }
}