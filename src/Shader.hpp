#pragma once

#include <fstream>
#include <stdexcept>
#include "glm/fwd.hpp"


class Shader {
public:

    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;

    void use() const;

    void setMat4 (const std::string &name, const glm::mat4 &mat) const;

private:
    unsigned int shaderProgram = 0;

    void compileShaders(std::string vertexSource, std::string fragmentSource);

    static std::string getFileData(const std::string& filepath);
};
