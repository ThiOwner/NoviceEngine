#pragma once

#include <vector>
#include <memory>

#include "../Components/Component.hpp"
#include "../Components/Transform.hpp"

class GameObject {
public:
    GameObject();

    template<typename T, typename... Args>
    T* addComponent(Args&&... args) {
        auto newComponent = std::make_unique<T>(std::forward<Args>(args)...);
        newComponent->parent = this;
        T* ptr = newComponent.get();
        components.push_back(std::move(newComponent));
        return ptr;
    }

    template<typename T>
    T* getComponent() {
        for (auto& comp : components) {
            if (auto* target = dynamic_cast<T*>(comp.get())) {
                return target;
            }
        }
        return nullptr;
    }


    void update(float deltaTime);

    void render();

    Transform* getTransform();

private:
    Transform* transform = nullptr;
    std::vector<std::unique_ptr<Component>> components;
};

