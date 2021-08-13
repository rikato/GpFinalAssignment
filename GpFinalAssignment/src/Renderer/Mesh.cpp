#include "Mesh.h"

#include "../vendor/objloader/objloader.h" 
#include "../Renderer/Shader.h"

Mesh::Mesh(const std::string& path)
    :m_Vao(0)
{
    // Load the object file.
    loadOBJ(&path[0], m_Vertices, m_Uvs, m_Normals);
}

Mesh::Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec3> normals, std::vector<glm::vec2> uvs, char drawingMode)
    :m_Vertices(vertices), m_Normals(normals), m_Uvs(uvs), m_DrawingMode(drawingMode)
{

}

void Mesh::SetShader(Shader* shader)
{
    m_Shader = shader;

    Create();
}

void Mesh::Draw()
{
    glBindVertexArray(m_Vao);
    glDrawArrays(m_DrawingMode, 0, m_Vertices.size());
    glBindVertexArray(0);
}

void Mesh::Create()
{
    unsigned int vboVertices, vboNormals, vboUvs;

    // Get vertex attributes
    unsigned int position_id = glGetAttribLocation(m_Shader->m_RendererId, "position");
    unsigned int normal_id = glGetAttribLocation(m_Shader->m_RendererId, "normal");
    unsigned int uv_id = glGetAttribLocation(m_Shader->m_RendererId, "uv");

    // vbo vertices.
    glGenBuffers(1, &vboVertices);
    glBindBuffer(GL_ARRAY_BUFFER, vboVertices);
    glBufferData(GL_ARRAY_BUFFER, m_Vertices.size() * sizeof(glm::vec3), &m_Vertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // vbo vertices.
    glGenBuffers(1, &vboNormals);
    glBindBuffer(GL_ARRAY_BUFFER, vboNormals);
    glBufferData(GL_ARRAY_BUFFER, m_Normals.size() * sizeof(glm::vec3), &m_Normals[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // vbo vertices.
    glGenBuffers(1, &vboUvs);
    glBindBuffer(GL_ARRAY_BUFFER, vboUvs);
    glBufferData(GL_ARRAY_BUFFER, m_Uvs.size() * sizeof(glm::vec2), &m_Uvs[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenVertexArrays(1, &m_Vao);
    glBindVertexArray(m_Vao);

    // Now bind the vertices vbo to the vao.
    glBindBuffer(GL_ARRAY_BUFFER, vboVertices);
    // Use '0' as stride, since vertices are in single array.
    glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(position_id);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Now bind the vertices vbo to the vao.
    glBindBuffer(GL_ARRAY_BUFFER, vboNormals);
    // Use '0' as stride, since vertices are in single array.
    glVertexAttribPointer(normal_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(normal_id);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Now bind the vertices vbo to the vao.
    glBindBuffer(GL_ARRAY_BUFFER, vboUvs);
    // Use '0' as stride, since vertices are in single array.
    glVertexAttribPointer(uv_id, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(uv_id);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}
