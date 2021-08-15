#version 460 core

// Matrices uniforms.
uniform mat4 mv;
uniform mat4 projection;
uniform vec3 lightPosition;

// Input for vertex.
in vec3 position;
in vec3 normal;

out VS_OUT
{
    // Normal.
    vec3 N;
    // LightPosition. 
    vec3 L;
    // Vector.
    vec3 V;
}
vs_out;

in vec2 uv;
out vec2 UV;

void main()
{
    UV = uv;

    //  View space calculation.
    vec4 P = mv * vec4(position, 1.0);

    // View space calculation normal 
    vs_out.N = mat3(mv) * normal;

    // Light vector calculation.
    vs_out.L = lightPosition - P.xyz;

    // View vector calculation.
    vs_out.V = -P.xyz;

    // Clip space.
    gl_Position = projection * P;
}