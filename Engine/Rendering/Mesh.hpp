#pragma once

#include "../Include/glad/glad.h"
#include "../Core/Types.hpp"
#include <vector>

class Mesh {
public:
    explicit Mesh(const std::vector<Vertex>& v, const std::vector<GLuint>& i);
    ~Mesh();

    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;

    void draw();

private:
    GLuint VAO{0}, VBO{0}, EBO{0};
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    void initBuffers();
};