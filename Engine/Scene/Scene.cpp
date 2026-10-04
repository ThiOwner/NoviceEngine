#include "Scene.hpp"

#include <algorithm>

void Scene::update(float deltaTime) {
    for (auto& object : _objects){
        object->update(deltaTime);
    }

    for (auto& object : _pendingObjects) {
        _objects.push_back(std::move(object));
    }
    _pendingObjects.clear();

    for (GameObject* object : _objectsToDestroy){
        _objects.erase(
        std::remove_if(_objects.begin(), _objects.end(),
            [object](const auto& ptr)
            {
                return ptr.get() == object;
            }),_objects.end()
        );
    }
    _objectsToDestroy.clear();
}

void Scene::destroyGameObject(GameObject* object) {
    _objectsToDestroy.push_back(object);
}

std::vector<GameObject*> Scene::getGameObjects() {
    std::vector<GameObject*> result;
    result.reserve(_objects.size());

    for (auto& object : _objects) {
        result.push_back(object.get());
    }
    return result;
}

Camera* Scene::getActiveCamera() const { return _activeCamera; }

void Scene::setActiveCamera(Camera* activeCamera) { _activeCamera = activeCamera; }