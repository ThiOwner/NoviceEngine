#pragma once

#include "GameObject.hpp"
#include "Components/Camera.hpp"
#include <memory>
#include <string>
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
        _pendingObjects.push_back(std::move(object));
        return ptr;
    }

    void destroyGameObject(GameObject* object);

    Camera* getActiveCamera() const;
    void setActiveCamera(Camera* activeCamera);

    std::vector<GameObject*> getGameObjects();

private:
    std::vector<std::unique_ptr<GameObject>> _objects;
    std::vector<std::unique_ptr<GameObject>> _pendingObjects;
    std::vector<GameObject*> _objectsToDestroy;

    Camera* _activeCamera = nullptr;
};