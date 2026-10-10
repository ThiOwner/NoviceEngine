#version 330 core

// Directional light uniforms
uniform vec3 u_lightDirection;
uniform vec3 u_dirLightColor;
uniform float u_dirLightIntensity;

// Material uniforms
uniform vec3 u_ambient;
uniform vec3 u_diffuse;
uniform vec3 u_specular;

uniform float u_ambientIntensity;
uniform float u_diffuseIntensity;
uniform float u_specularIntensity;
uniform float u_shininess;

// Input
in vec3 vNormal;
in vec3 vPosition;

// Output
out vec4 FragColor;

void main()
{
    vec3 normal = normalize(vNormal);
    vec3 lightDir = normalize(u_lightDirection);
    vec3 lightColor = u_dirLightColor * u_dirLightIntensity;

    vec4 ambient = vec4(u_ambientIntensity * u_ambient, 1.0);

    float angle1 = max(0.0, dot(lightDir, normal));
    vec4 diffuse = vec4(u_diffuseIntensity * u_diffuse * lightColor, 1.0) * angle1;

    vec4 specular = vec4(0.0);

    if (angle1 > 0.0){
        vec3 viewVector = normalize(-vPosition);
        vec3 reflectedVector = reflect(-lightDir, normal);
        float angle2 = pow(max(0.0, dot(reflectedVector, viewVector)), u_shininess);
        specular = vec4(u_specularIntensity * u_specular * lightColor, 1.0) * angle2;
    }

    FragColor = diffuse + ambient + specular;
}