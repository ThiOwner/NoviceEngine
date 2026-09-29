#pragma once

#include "glad/glad.h"
#include "Types.hpp"
#include <vector>

class Mesh {
public:
    explicit Mesh(const std::vector<Vertex>& v);
    ~Mesh();

    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;

    void draw();

private:
    GLuint VAO{0}, VBO{0};
    std::vector<Vertex> vertices;
    void initBuffers();
};