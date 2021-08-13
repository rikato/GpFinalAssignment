#include "Object.h"
#include <glad/glad.h>

Object::Object(Mesh* mesh, Shader* shader, Material* material)
	:m_Mesh(nullptr), m_Shader(nullptr), m_Transform(glm::translate(glm::mat4(1.0), glm::vec3(0, 0, 0))), m_Material(nullptr)
{
	m_Mesh = mesh;
	m_Shader = shader;
	m_Material = material;

	m_Mesh->SetShader(shader);

	// Set the uniform texture for the shader.
	m_Shader->SetDiffuseMap(m_Material->m_TextureId);
}

Object::~Object()
{
	delete m_Mesh;
	delete m_Shader;
}

void Object::Update(glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
{
	m_Shader->Bind();

	m_Shader->UpdateMv(viewMatrix * m_Transform);
	m_Shader->UpdateProjection(projectionMatrix);

	glUniform1i(6, 0);
	glActiveTexture(GL_TEXTURE0 + 6);
	glBindTexture(GL_TEXTURE_2D, m_Material->m_NormalId);

	glUniform1i(0, 1);
	glActiveTexture(GL_TEXTURE0  + 1);
	glBindTexture(GL_TEXTURE_2D, m_Material->m_TextureId);

	m_Mesh->Draw();
}
