#include "Shader.hpp"

#define infoLogSize 1024

#include <string>
#include <sstream>
#include <stdexcept>
#include "../Include/glad/glad.h"
#include "glm/gtc/type_ptr.hpp"

Shader::Shader(const std::string &vertexPath, const std::string &fragmentPath) {
    this->compileShaders(getFileData(vertexPath), getFileData(fragmentPath));
}

Shader::~Shader(){ glDeleteProgram(shaderProgram); }

void Shader::compileShaders(const std::string& vertexSource,const std::string& fragmentSource) {
    int  success;
    char infoLog[infoLogSize];

    const unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

    const GLchar* vertexSrc = vertexSource.c_str();
    glShaderSource(vertexShader, 1, &vertexSrc, nullptr);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(vertexShader, infoLogSize, nullptr, infoLog);
        throw std::runtime_error("Failed to compile vertex shader :" + std::string(infoLog));
    }

    const unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    const GLchar* fragmentSrc = fragmentSource.c_str();
    glShaderSource(fragmentShader, 1, &fragmentSrc, nullptr);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if(!success) {
        glGetShaderInfoLog(fragmentShader, infoLogSize, nullptr, infoLog);
        throw std::runtime_error("Failed to compile fragment shader :" + std::string(infoLog));
    }

    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);


    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, infoLogSize, NULL, infoLog);
        throw std::runtime_error("Failed to compile shader program :" + std::string(infoLog));
    }

    // Clean up
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

std::string Shader::getFileData(const std::string& filepath) {
    std::ifstream file(filepath);

    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file : " + filepath);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    file.close();
    return buffer.str();
}