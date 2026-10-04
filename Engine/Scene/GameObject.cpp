#include "GameObject.hpp"
#include <algorithm>

void GameObject::update(float deltaTime) {
    for (auto& component : _components) {
        component->update(deltaTime);
    }

    for (auto& component : _pendingComponents) {
        _components.push_back(std::move(component));
        component->start();
    }
    _pendingComponents.clear();

    for (Component* component: _componentsToDestroy){
        _components.erase(
        std::remove_if(_components.begin(), _components.end(),
            [component](const auto& ptr)
            {
                return ptr.get() == component;
            }),_components.end()
        );
    }
    _componentsToDestroy.clear();
}

void GameObject::removeComponent(Component* component) {
    _componentsToDestroy.push_back(component);
}

std::vector<Component*> GameObject::getComponents() {
    std::vector<Component*> result;
    result.reserve(_components.size());

    for (auto& component : _components) {
        result.push_back(component.get());
    }
    return result;
}