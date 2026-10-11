#include "GameObject.hpp"
#include <algorithm>

void GameObject::update(const FrameContext& context) {
    processingPendingComponents();
    for (auto& component : _components) {
        if (!component->isActive) continue;
        if (component->hasStarted) {
            component->hasStarted = true;
            component->start(context);
        }
        component->update(context);
    }
    processingDestroyComponents();
}

void GameObject::processingPendingComponents() {
    for (auto& component : _pendingComponents) {
        Component* ptr = component.get();
        ptr->owner = this;
        _components.push_back(std::move(component));
    }
    _pendingComponents.clear();
}

void GameObject::processingDestroyComponents() {
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