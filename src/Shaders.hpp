#pragma once

#include "glad/glad.h"
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "glm/fwd.hpp"
#include "glm/detail/type_mat4x4.hpp"
#include "glm/gtc/type_ptr.hpp"

class Shaders {
public:

    Shaders(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shaders();

    Shaders(const Shaders&) = delete;
    Shaders& operator=(const Shaders&) = delete;

    void compileShaders();

    void use() const;

    static void setMat4(const std::string &name, const glm::mat4 &mat);

private:
    static inline unsigned int activeProgram = 0;

    [[nodiscard]] const char* getVertexSource() const {return vertexShaderSource.c_str();}
    [[nodiscard]] const char* getFragmentSource() const {return fragmentShaderSource.c_str();}

    std::string vertexShaderSource;
    std::string fragmentShaderSource;

    unsigned int shaderProgram{0};

    static std::string getFileData(const std::string& filepath) {
        std::ifstream file(filepath);

        if (!file.is_open()) {
            throw std::runtime_error("Couldn't open file : " + filepath);
        }

        std::stringstream buffer;
        buffer << file.rdbuf();

        file.close();
        return buffer.str();
    }
};
