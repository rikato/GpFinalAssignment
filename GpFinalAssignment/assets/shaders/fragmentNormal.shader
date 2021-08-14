#version 460 core

// Input from vertex shader
in VS_OUT
{
    vec3 N; // Normal
    vec3 L; // LightPosition
    vec3 V; // Vertex
}
fs_in;

in vec2 UV;

// Material properties
uniform vec3 materialAmbientColor;
uniform vec3 materialDiffuseColor;
uniform vec3 materialSpecularColor;
uniform float materialRoughness;

uniform sampler2D diffuseMap;
uniform sampler2D normalMap;

void main()
{
    // Normalize the incoming N, L and V vectors
    vec3 L = normalize(fs_in.L);
    vec3 V = normalize(fs_in.V);

    vec3 normal = normalize(texture2D(normalMap, UV).xyz * 2.0f - 1.0f);

    // Calculate R locally
    vec3 R = reflect(-L, normal);

    // Compute the diffuse and specular components for each fragment
    vec3 diffuse = max(dot(normal, L), 0.0) * texture2D(diffuseMap, UV).rgb * materialDiffuseColor;
    vec3 specular = pow(max(dot(R, V), 0.0), materialRoughness) * materialSpecularColor;

    // Write final color to the framebuffer
    gl_FragColor = vec4(materialAmbientColor + diffuse + specular, 1.0);
} 