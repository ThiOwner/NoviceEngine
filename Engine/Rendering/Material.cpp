#include "Material.hpp"

Material::Material(Shader *shader) : _shader(shader) { }

void Material::bind() {
    _shader->bind();
    _shader->setFloat("u_shininess", shininess);
    _shader->setFloat("u_reflectivity", reflectivity);

    _shader->setFloat("u_ambientIntensity", ambientIntensity);
    _shader->setFloat("u_diffuseIntensity", diffuseIntensity);
    _shader->setFloat("u_specularIntensity", specularIntensity);

    _shader->setVec3("u_ambient", ambient);
    _shader->setVec3("u_diffuse", diffuse);
    _shader->setVec3("u_specular", specular);
}

void Material::unbind() {
    _shader->unbind();
}

Shader* Material::getShader() {
    return _shader;
}