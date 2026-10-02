#pragma once

#include <string>
#include <unordered_map>

// Forward declarations
struct MeshData;

// Asset Manager class
class AssetManager {
public:
    static MeshData* loadMesh(const std::string& path);

private:
    static std::unordered_map<std::string, MeshData> meshes ;
};
