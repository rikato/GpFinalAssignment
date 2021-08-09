#include "Object.h"

Object::Object(Mesh* mesh, Shader* shader)
	:m_Mesh(nullptr), m_Shader(nullptr), m_Transform(glm::translate(glm::mat4(1.0), glm::vec3(0, 0, 0)))
{
	m_Mesh = mesh;
	m_Shader = shader;

	m_Shader->Bind();
}

Object::~Object()
{
	delete m_Mesh;
	delete m_Shader;
}

void Object::Update(glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
{
	m_Shader->updateMv(viewMatrix * m_Transform);
	m_Shader->updateProjection(projectionMatrix);

	m_Mesh->Draw();
}
