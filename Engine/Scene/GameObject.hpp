#pragma once

#include <memory>
#include <vector>
#include "Core/FrameContext.hpp"
#include "Components/Transform.hpp"

class GameObject {
public:
    GameObject() = default;
    virtual ~GameObject() = default;

    virtual void update(const FrameContext& context);

    template<typename T, typename... Args>
    T* addComponent(Args&&... args) {
        static_assert(std::is_base_of_v<Component, T>);
        auto component = std::make_unique<T>(
            std::forward<Args>(args)...
        );

        T* ptr = component.get();
        ptr->owner = this;
        ptr->awake();

        _pendingComponents.push_back(std::move(component));
        return ptr;
    }

    void removeComponent(Component* component);

    template<typename T>
    T* getComponent() {
        for (const auto& component : _components) {
            if (T* castedComponent = dynamic_cast<T*>(component.get())) {
                return castedComponent;
            }
        }
        return nullptr;
    }

    Transform* getTransform();

    Transform transform;

private:
    std::vector<std::unique_ptr<Component>> _components;
    std::vector<std::unique_ptr<Component>> _pendingComponents;
    std::vector<Component*> _componentsToDestroy;
};
