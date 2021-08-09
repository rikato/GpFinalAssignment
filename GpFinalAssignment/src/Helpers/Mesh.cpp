#include "Mesh.h"

#include <glad/glad.h>

#include "../vendor/objloader/objloader.h" 
#include "../Renderer/Shader.h"

Mesh::Mesh(std::string path)
    :vao(0)
{
    // Load the object file.
    if (loadOBJ(&path[0], this->vertices, this->normals, this->uvs)) 
    {
        // After succesfully loading the object, create it.
        this->Create();
    }
}

void Mesh::Draw()
{
    glBindVertexArray(this->vao);
    glDrawArrays(GL_TRIANGLES, 0, this->vertices.size());
    glBindVertexArray(0);
}

void Mesh::Create()
{
    unsigned int vbo;

    // Bind vao.
    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    // vbo vertices.
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(glm::vec3), &this->vertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Now bind the vbo to the vao.
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // Use '0' as stride, since vertices are in single array.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}
