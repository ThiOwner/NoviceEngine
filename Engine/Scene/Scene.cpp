#include "Scene.hpp"

#include <algorithm>

void Scene::update(float deltaTime) {
    for (auto& object : objects){
        object->update(deltaTime);
    }

    for (auto& object : pendingObjects) {
        objects.push_back(std::move(object));
    }
    pendingObjects.clear();

    for (GameObject* object : objectsToDestroy){
        objects.erase(
        std::remove_if(objects.begin(), objects.end(),
            [object](const auto& ptr)
            {
                return ptr.get() == object;
            }),objects.end()
        );
    }
    objectsToDestroy.clear();
}

void Scene::destroyGameObject(GameObject* object) {
    objectsToDestroy.push_back(object);
}

std::vector<GameObject*> Scene::getGameObjects() {
    std::vector<GameObject*> result;
    result.reserve(objects.size());

    for (auto& object : objects) {
        result.push_back(object.get());
    }
    return result;
}