#pragma once

#include "../Include/glad/glad.h"
#include "../Core/Types.hpp"

class Mesh {
public:
    explicit Mesh(const MeshData& meshData);
    ~Mesh();

    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;

    GLuint getVAO();
    int getIndexCount();

private:
    GLuint _VAO{0}, _VBO{0}, _EBO{0};
    std::vector<Vertex> _vertices;
    std::vector<GLuint> _indices;
    void initBuffers();
};