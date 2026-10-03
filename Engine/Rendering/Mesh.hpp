#pragma once

#include "../Include/glad/glad.h"
#include "../Core/Types.hpp"

class Mesh {
public:
    explicit Mesh(const MeshData& meshData);
    ~Mesh();

    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;

private:
    GLuint VAO{0}, VBO{0}, EBO{0};
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    void initBuffers();
};