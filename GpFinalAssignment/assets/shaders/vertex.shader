#version 460 core

// Uniform matrices
uniform mat4 mv;
uniform mat4 projection;
//uniform vec3 lightPosition;

// Per-vertex inputs
in vec3 position;
in vec3 normal;

out VS_OUT
{
    vec3 N; // Normal in view space
    vec3 L; // Light vector
    vec3 V; // View-space vector
}
vs_out;

in vec2 uv;
out vec2 UV;

void main()
{
    UV = uv;

    // Calculate view-space coordinate
    vec4 P = mv * vec4(position, 1.0);

    // Calculate normal in view-space
    vs_out.N = mat3(mv) * normal;

    // Calculate light vector
    vs_out.L = vec3(0, 4, 4) - P.xyz;

    // Calculate view vector;
    vs_out.V = -P.xyz;

    // Calculate the clip-space position of each vertex
    gl_Position = projection * P;
}