#include "Mesh.h"

#include <glad/glad.h>

#include "../vendor/objloader/objloader.h" 
#include "../Renderer/Shader.h"

Mesh::Mesh(std::string path)
    :m_Vao(0)
{
    // Load the object file.
    if (loadOBJ(&path[0], m_Vertices, m_Normals, m_Uvs)) 
    {
        // After succesfully loading the object, create it.
        Create();
    }
}

void Mesh::Draw()
{
    glBindVertexArray(m_Vao);
    glDrawArrays(GL_TRIANGLES, 0, m_Vertices.size());
    glBindVertexArray(0);
}

void Mesh::Create()
{
    unsigned int vbo;

    // Bind vao.
    glGenVertexArrays(1, &m_Vao);
    glBindVertexArray(m_Vao);

    // vbo vertices.
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, m_Vertices.size() * sizeof(glm::vec3), &m_Vertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Now bind the vbo to the vao.
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // Use '0' as stride, since vertices are in single array.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}
