#pragma once

#include <string>
#include "../Core/Utils/Types.hpp"

struct IndexKey {
    int vertexIndex; int normalIndex; int texcoordIndex;
    bool operator<(const IndexKey& other) const {
        if (vertexIndex != other.vertexIndex) return vertexIndex < other.vertexIndex;
        if (normalIndex != other.normalIndex) return normalIndex < other.normalIndex;
        return texcoordIndex < other.texcoordIndex;
    }
};

MeshData loadOBJ(const std::string& path);