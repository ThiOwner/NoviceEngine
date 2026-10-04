#pragma once

#include <fstream>
#include "glm/fwd.hpp"


class Shader {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;

    void bind();
    void unbind();

private:
    unsigned int _shaderProgram = 0;

    void compileShaders(const std::string& vertexSource,const std::string& fragmentSource);

    static std::string getFileData(const std::string& filepath);
};
