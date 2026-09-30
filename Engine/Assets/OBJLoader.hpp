#pragma once

#include <vector>
#include <string>
#include "../Engine/Core/Types.hpp"

struct MeshData {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
};

struct IndexKey {
    int vertexIndex; int normalIndex; int texcoordIndex;
    bool operator<(const IndexKey& other) const {
        if (vertexIndex != other.vertexIndex) return vertexIndex < other.vertexIndex;
        if (normalIndex != other.normalIndex) return normalIndex < other.normalIndex;
        return texcoordIndex < other.texcoordIndex;
    }
};

MeshData loadOBJ(const std::string& path);