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

Shader::~Shader(){ glDeleteProgram(_shaderProgram); }

void Shader::bind(){ glUseProgram(_shaderProgram); }

void Shader::unbind(){ glUseProgram(0); }

// TODO : adding a cache for storing already fetched uniforms.
void Shader::setMat4(const std::string &name, const glm::mat4 &matrix) {
     glUniformMatrix4fv(glGetUniformLocation(_shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(matrix));
}

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

    _shaderProgram = glCreateProgram();

    glAttachShader(_shaderProgram, vertexShader);
    glAttachShader(_shaderProgram, fragmentShader);
    glLinkProgram(_shaderProgram);


    glGetProgramiv(_shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(_shaderProgram, infoLogSize, NULL, infoLog);
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