#include "GameObject.hpp"


GameObject::GameObject() {
    { transform = addComponent<Transform>(); }
}

void GameObject::update(float deltaTime) {
    for (auto& comp : components) {
        comp->update(deltaTime);
    }
}

void GameObject::render() {
    for (auto& comp : components) {
        comp->render();
    }
}

Transform* GameObject::getTransform() { return transform; }