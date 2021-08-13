#pragma once
#include "glm/glm.hpp" 
#include "../Renderer/Mesh.h" 
#include "../Renderer/Shader.h"
#include "../Renderer/Material.h"

class Object {
public:
	Object(Mesh* mesh, Shader* shader, Material* material);
	~Object();

	void Update(glm::mat4 viewMatrix, glm::mat4 projectionMatrix);

	Mesh* m_Mesh;
	Shader* m_Shader;
	Material* m_Material;
	glm::mat4 m_LocalTransform;
};