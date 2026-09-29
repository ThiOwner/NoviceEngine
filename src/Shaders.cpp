#include "Shaders.hpp"

Shaders::Shaders(const std::string &vertexPath, const std::string &fragmentPath) {
    vertexShaderSource = getFileData(vertexPath);
    fragmentShaderSource = getFileData(fragmentPath);
    this->compileShaders();
}

Shaders::~Shaders(){glDeleteProgram(shaderProgram);}

void Shaders::use() const {
    glUseProgram(shaderProgram);
    activeProgram = shaderProgram;
}

void Shaders::setMat4(const std::string &name, const glm::mat4 &mat) {
    glUniformMatrix4fv(glGetUniformLocation(activeProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shaders::compileShaders() {
    int  success;
    char infoLog[512];

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

    const char* vertexSrc = getVertexSource();
    glShaderSource(vertexShader, 1, &vertexSrc, nullptr);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        throw std::runtime_error("Failed to compile vertex shader :" + std::string(infoLog));
    }

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    const char* fragmentSrc = getFragmentSource();
    glShaderSource(fragmentShader, 1, &fragmentSrc, nullptr);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if(!success) {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        throw std::runtime_error("Failed to compile fragment shader :" + std::string(infoLog));
    }

    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);


    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        throw std::runtime_error("Failed to compile shader program :" + std::string(infoLog));
    }

    // Clean up
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}