#pragma once

#include "Rendering/Mesh.hpp"
#include "Rendering/Shader.hpp"

#include <memory>
#include <string>
#include <unordered_map>

// Asset Manager class
class AssetManager {
public:
    static std::shared_ptr<Mesh> loadMesh(const std::string& path);

    static std::shared_ptr<Shader> loadShader(const std::string& name,
        const std::string& vertexShaderPath,
        const std::string& fragmentShaderPath);

    static std::shared_ptr<Shader> getShader(const std::string& name);

private:
    static std::unordered_map<std::string, std::shared_ptr<Mesh>> meshes ;
    static std::unordered_map<std::string, std::shared_ptr<Shader>> shaders;
};
