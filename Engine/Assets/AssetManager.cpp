#include "AssetManager.hpp"
#include "OBJLoader.hpp"

std::unordered_map<std::string, std::shared_ptr<Mesh>> AssetManager::meshes ;
std::unordered_map<std::string, std::shared_ptr<Shader>> AssetManager::shaders;

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

std::shared_ptr<Shader> AssetManager::loadShader(const std::string& name,
    const std::string& vertexShaderPath,
    const std::string& fragmentShaderPath)
{
    auto it = shaders.find(name);
    if (it != shaders.end()) {
        return it->second;
    }

    auto [iterator, inserted] = shaders.emplace(
        name,
        std::make_shared<Shader>(vertexShaderPath, fragmentShaderPath)
    );

    return iterator->second;
}

std::shared_ptr<Shader> AssetManager::getShader(const std::string& name) {
    auto it = shaders.find(name);
    if (it != shaders.end()) {
        return it->second;
    }
    throw std::runtime_error("Shader \"" + name + "\" does not exist.");
}