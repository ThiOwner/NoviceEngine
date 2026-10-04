#include "AssetManager.hpp"
#include "OBJLoader.hpp"

std::unordered_map<std::string, std::shared_ptr<Mesh>> AssetManager::_meshes ;
std::unordered_map<std::string, std::shared_ptr<Shader>> AssetManager::_shaders;

Mesh* AssetManager::loadMesh(const std::string &path) {
    auto it = _meshes.find(path);
    if (it != _meshes.end()) {
        return it->second.get();
    }

    auto [iterator, inserted] = _meshes.emplace(
        path,
        std::make_shared<Mesh>(loadOBJ(path))
    );

    return iterator->second.get();
}

std::shared_ptr<Shader> AssetManager::loadShader(const std::string& name,
    const std::string& vertexShaderPath,
    const std::string& fragmentShaderPath)
{
    auto it = _shaders.find(name);
    if (it != _shaders.end()) {
        return it->second;
    }

    auto [iterator, inserted] = _shaders.emplace(
        name,
        std::make_shared<Shader>(vertexShaderPath, fragmentShaderPath)
    );

    return iterator->second;
}

Shader* AssetManager::getShader(const std::string& name) {
    auto it = _shaders.find(name);
    if (it != _shaders.end()) {
        return it->second.get();
    }
    throw std::runtime_error("Shader \"" + name + "\" does not exist.");
}