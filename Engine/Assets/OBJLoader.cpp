#define TINYOBJLOADER_IMPLEMENTATION
#include "../Include/tiny_obj_loader.h"

#include "OBJLoader.hpp"
#include <iostream>
#include <map>

MeshData loadOBJ(const std::string& path) {
    tinyobj::ObjReaderConfig readerConfig;
    tinyobj::ObjReader reader;

    if (!reader.ParseFromFile(path, readerConfig)) {
        if (!reader.Error().empty()) {
            throw std::runtime_error("TinyOBJLoader error: " + reader.Error());
        }
    }

    auto& attrib = reader.GetAttrib();
    auto& shapes = reader.GetShapes();

    MeshData meshData;
    std::map<IndexKey, unsigned int> uniqueVertices;

    for (const auto& shape : shapes) {
        for (const auto& index : shape.mesh.indices) {
            IndexKey key{index.vertex_index, index.normal_index, index.texcoord_index};

            if (uniqueVertices.find(key) == uniqueVertices.end()) {
                Vertex vertex;

                vertex.position = glm::vec3(
                    attrib.vertices[3 * index.vertex_index + 0],
                    attrib.vertices[3 * index.vertex_index + 1],
                    attrib.vertices[3 * index.vertex_index + 2]
                );

                if (index.normal_index >= 0) {
                    vertex.normal = glm::vec3(
                        attrib.normals[3 * index.normal_index + 0],
                        attrib.normals[3 * index.normal_index + 1],
                        attrib.normals[3 * index.normal_index + 2]
                    );
                } else {
                    vertex.normal = glm::vec3(0.0f);
                }

                unsigned int newIndex = static_cast<unsigned int>(meshData.vertices.size());
                uniqueVertices[key] = newIndex;
                meshData.vertices.push_back(vertex);
                meshData.indices.push_back(newIndex);
            } else {
                meshData.indices.push_back(uniqueVertices[key]);
            }
        }
    }

    return meshData;
}