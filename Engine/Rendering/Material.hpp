#pragma once
#include "glm/vec3.hpp"
#include "Shader.hpp"

class Material {
public:
    Material(Shader* shader);

    void bind();
    void unbind();

    Shader* getShader();

    float shininess = 32.0f;
    float reflectivity = 0.0f;

    float ambientIntensity = 1.0f;
    float diffuseIntensity = 1.0f;
    float specularIntensity = 1.0f;

    glm::vec3 ambient {0.1f}, diffuse {0.35f}, specular {1.0f};

private:
    Shader* _shader;

};
