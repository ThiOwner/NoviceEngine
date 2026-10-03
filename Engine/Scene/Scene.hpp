#pragma once

#include "GameObject.hpp"
#include <memory>
#include <vector>

class Scene {
public:
    Scene() = default;

    void update(float deltaTime);

    template<typename T, typename... Args>
    T* addGameObject(Args&&... args) {
        static_assert(std::is_base_of_v<GameObject, T>);
        auto object = std::make_unique<T>(
            std::forward<Args>(args)...
        );

        T* ptr = object.get();
        pendingObjects.push_back(std::move(object));
        return ptr;
    }

    void destroyGameObject(GameObject* object);

private:
    std::vector<std::unique_ptr<GameObject>> objects;
    std::vector<std::unique_ptr<GameObject>> pendingObjects;
    std::vector<GameObject*> objectsToDestroy;
};