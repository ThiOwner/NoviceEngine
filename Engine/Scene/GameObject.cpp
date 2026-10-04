#include "GameObject.hpp"
#include <algorithm>

void GameObject::update(float deltaTime) {
    for (auto& component : components) {
        component->update(deltaTime);
    }

    for (auto& component : pendingComponents) {
        components.push_back(std::move(component));
        component->start();
    }
    pendingComponents.clear();

    for (Component* component: componentsToDestroy){
        components.erase(
        std::remove_if(components.begin(), components.end(),
            [component](const auto& ptr)
            {
                return ptr.get() == component;
            }),components.end()
        );
    }
    componentsToDestroy.clear();
}

void GameObject::removeComponent(Component* component) {
    componentsToDestroy.push_back(component);
}

std::vector<Component*> GameObject::getComponents() {
    std::vector<Component*> result;
    result.reserve(components.size());

    for (auto& component : components) {
        result.push_back(component.get());
    }
    return result;
}