#version 460 core

// Uniform matrices
uniform mat4 mv;
uniform mat4 projection;

// Per-vertex inputs
in vec3 position;

void main()
{
    // Calculate view-space coordinate
    vec4 P = mv * vec4(position, 1.0);

    // Calculate the clip-space position of each vertex
    gl_Position = projection * P;
}