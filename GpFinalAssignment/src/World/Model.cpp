#include "Model.h"

Model::Model(std::vector<Object*> objects, glm::vec3 translation)
	:m_Objects(objects)
{
	m_GloablTransform = glm::translate(glm::mat4(1.0f), translation);
}

void Model::Update(glm::mat4 viewMatrix, glm::mat4 projectionMatrix, double deltaTime)
{
	for (auto object : m_Objects) 
	{
		object->Update(viewMatrix * m_GloablTransform, projectionMatrix, deltaTime);
	}
}


