#pragma once
#include "glm/glm.hpp" 
#include "../Renderer/Mesh.h" 
#include "../Renderer/Shader.h"

class Object {
public:
	Object(Mesh* mesh, Shader* shader);
	~Object();

	void Update(glm::mat4 viewMatrix, glm::mat4 projectionMatrix);

	Mesh* m_Mesh;
	Shader* m_Shader;
	glm::mat4 m_Transform;
};