#version 460 core

// The input from the vertex shader.
in VS_OUT
{
    // Normal.
    vec3 N; 
    // LightPosition.
    vec3 L; 
    // Vertex.
    vec3 V; 
}
fs_in;

in vec2 UV;

// Properties of material.
uniform vec3 materialAmbientColor;
uniform vec3 materialDiffuseColor;
uniform vec3 materialSpecularColor;
uniform float materialRoughness;

uniform sampler2D diffuseMap;
uniform sampler2D normalMap;

void main()
{
    // Normalize the N, L and V vectors.
    vec3 L = normalize(fs_in.L);
    vec3 V = normalize(fs_in.V);

    vec3 normal = normalize(texture2D(normalMap, UV).xyz * 2.0f - 1.0f);

    // Calculate reflection local.
    vec3 R = reflect(-L, normal);

    // Diffuse and specular calculations of components for each fragment.
    // Also taking normal map into account.
    vec3 diffuse = max(dot(normal, L), 0.0) * texture2D(diffuseMap, UV).rgb * materialDiffuseColor;
    vec3 specular = pow(max(dot(R, V), 0.0), materialRoughness) * materialSpecularColor;

    // Color to the framebuffer,
    gl_FragColor = vec4(materialAmbientColor + diffuse + specular, 1.0);
} 