#include "Object.h"
#include <glad/glad.h>

Object::Object(Mesh* mesh, Shader* shader, Material* material, Animation* animation)
	:m_Mesh(mesh), m_Shader(shader), m_LocalTransform(glm::translate(glm::mat4(1.0), glm::vec3(0, 0, 0))), m_Material(material), m_Animation(animation)
{
	m_Mesh->SetShader(shader);
}

Object::~Object()
{
	delete m_Mesh;
	delete m_Shader;
}

void Object::Update(glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
{
	m_Shader->Bind();

	// If an animation is present on this object,
	// we need to update the objects local transform.
	if (m_Animation)
	{
		m_Shader->UpdateMv(viewMatrix * m_LocalTransform * m_Animation->Animate());
	}
	else 
	{
		m_Shader->UpdateMv(viewMatrix * m_LocalTransform);
	}

	m_Shader->UpdateProjection(projectionMatrix);

	for (auto texture : m_Material->m_Textures) 
	{
		texture->SetActive();
	}

	m_Mesh->Draw();
}
