#version 330 core

uniform vec3 u_ambient;
uniform vec3 u_diffuse;
uniform vec3 u_specular;

uniform float u_ambientIntensity;
uniform float u_diffuseIntensity;
uniform float u_specularIntensity;

uniform float u_shininess;
uniform float u_reflectivity;

in vec3 vNormal;
in vec3 vPosition;
in vec3 vLightPos;

out vec4 FragColor;

void main()
{
    vec3 normal = normalize(vNormal);

    vec4 ambient = vec4(u_ambientIntensity * u_ambient, 1.0);

    vec3 lightDir = normalize(vLightPos - vPosition);

    float angle1 = max(0.0, dot(lightDir, normal));
    vec4 diffuse = vec4(u_diffuseIntensity * u_diffuse, 1.0) * angle1;

    vec4 specular = vec4(0.0);

    if (angle1 > 0.0){
        vec3 viewVector = normalize(-vPosition);
        vec3 reflectedVector = reflect(-lightDir, normal);
        float angle2 = pow(max(0.0, dot(reflectedVector, viewVector)), u_shininess);
        specular = vec4(u_specularIntensity * u_specular, 1.0) * angle2;
    }

    FragColor = diffuse + ambient + specular;
}