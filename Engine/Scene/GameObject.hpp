#pragma once

#include <memory>
#include <vector>
#include "Components/Component.hpp"

class GameObject {
public:
    GameObject() = default;
    virtual ~GameObject() = default;

    virtual void update(float deltaTime);

    template<typename T, typename... Args>
    T* addComponent(Args&&... args) {
        static_assert(std::is_base_of_v<Component, T>);
        auto component = std::make_unique<T>(
            std::forward<Args>(args)...
        );

        T* ptr = component.get();
        ptr->owner = this;
        ptr->awake();

        pendingComponents.push_back(std::move(component));
        return ptr;
    }

    void removeComponent(Component* component);

    std::vector<Component*> getComponents();

private:
    std::vector<std::unique_ptr<Component>> components;
    std::vector<std::unique_ptr<Component>> pendingComponents;
    std::vector<Component*> componentsToDestroy;
};
