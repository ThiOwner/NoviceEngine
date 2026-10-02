#pragma once

#include "../Rendering/Mesh.hpp"
#include <memory>
#include <string>
#include <unordered_map>

// Asset Manager class
class AssetManager {
public:
    static std::shared_ptr<Mesh> loadMesh(const std::string& path);

private:
    static std::unordered_map<std::string, std::shared_ptr<Mesh>> meshes ;
};
