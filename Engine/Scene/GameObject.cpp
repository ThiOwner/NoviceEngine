#include "GameObject.hpp"
#include <algorithm>

void GameObject::update(const FrameContext& context) {
    for (auto& component : _components) {
        if (component->isActive) component->update(context);
    }

    for (auto& component : _pendingComponents) {
        Component* ptr = component.get();
        ptr->owner = this;
        _components.push_back(std::move(component));
        ptr->start();
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

Transform* GameObject::getTransform() {
    return &transform;
}