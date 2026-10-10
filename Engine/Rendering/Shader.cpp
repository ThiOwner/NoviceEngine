#include "Shader.hpp"

constexpr int infoLogSize = 1024;

#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include "glm/gtc/type_ptr.hpp"

Shader::Shader(const std::string &vertexPath, const std::string &fragmentPath) {
    this->compileShaders(getFileData(vertexPath), getFileData(fragmentPath));
}

Shader::~Shader(){ glDeleteProgram(_shaderProgram); }

void Shader::bind(){ glUseProgram(_shaderProgram); }

void Shader::unbind(){ glUseProgram(0); }

// TODO : adding a cache for storing already fetched uniforms.
int Shader::setMat4(const std::string &name, const glm::mat4 &matrix) {
    if (_fetchedUniforms.find(name) != _fetchedUniforms.end()) {
        glUniformMatrix4fv(_fetchedUniforms[name], 1, GL_FALSE, glm::value_ptr(matrix));
    } else {
        GLint loc = glGetUniformLocation(_shaderProgram, name.c_str());
        if (loc != -1) {
            _fetchedUniforms[name] = loc;
            glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(matrix));
        } else return -1;
    }
    return 0;
}
int Shader::setVec3(const std::string& name, const glm::vec3& vector) {
    if (_fetchedUniforms.find(name) != _fetchedUniforms.end()) {
        glUniform3fv(_fetchedUniforms[name], 1, &vector[0]);
    } else {
        GLint loc = glGetUniformLocation(_shaderProgram, name.c_str());
        if (loc != -1) {
            _fetchedUniforms[name] = loc;
            glUniform3fv(loc, 1, &vector[0]);
        } else return -1;
    }
    return 0;
}
int Shader::setFloat(const std::string& name, const float value) {
    if (_fetchedUniforms.find(name) != _fetchedUniforms.end()) {
        glUniform1f(_fetchedUniforms[name], value);
    } else {
        GLint loc = glGetUniformLocation(_shaderProgram, name.c_str());
        if (loc != -1) {
            _fetchedUniforms[name] = loc;
            glUniform1f(loc, value);
        } else return -1;
    }
    return 0;
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