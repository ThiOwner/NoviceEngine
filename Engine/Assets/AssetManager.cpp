#include "AssetManager.hpp"
#include "OBJLoader.hpp"

std::unordered_map<std::string, std::shared_ptr<Mesh>> AssetManager::meshes ;

std::shared_ptr<Mesh> AssetManager::loadMesh(const std::string &path) {
    auto it = meshes.find(path);
    if (it != meshes.end()) {
        return it->second;
    }

    auto [iterator, inserted] = meshes.emplace(
        path,
        std::make_shared<Mesh>(loadOBJ(path))
    );

    return iterator->second;
}
