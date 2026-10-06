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

    int setMat4(const std::string& name, const glm::mat4& matrix);
    int setVec3(const std::string& name, const glm::vec3& vector);
    int setFloat(const std::string& name, float value);

private:
    unsigned int _shaderProgram = 0;

    void compileShaders(const std::string& vertexSource,const std::string& fragmentSource);

    static std::string getFileData(const std::string& filepath);
};
