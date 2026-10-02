#include "AssetManager.hpp"
#include "OBJLoader.hpp"

#include <vector>

std::unordered_map<std::string, MeshData> AssetManager::meshes;

MeshData* AssetManager::loadMesh(const std::string &path) {
    auto it = meshes.find(path);
    if (it != meshes.end()) {
        return &it->second;
    }

    auto [iterator, inserted] = meshes.emplace(
        path,
        loadOBJ(path)
    );

    return &iterator->second;
}
