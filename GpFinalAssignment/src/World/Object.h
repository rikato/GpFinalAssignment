#pragma once
#include "glm/glm.hpp" 
#include "../Renderer/Mesh.h" 
#include "../Renderer/Shader.h"
#include "../Renderer/Material.h"
#include "../Renderer/Animation.h"

class Object {
public:
	Object(Mesh* mesh, Shader* shader, Material* material, Animation* animation = NULL);
	~Object();

	void Update(glm::mat4 viewMatrix, glm::mat4 projectionMatrix, double deltaTime);

	Mesh* m_Mesh;
	Shader* m_Shader;
	Material* m_Material;
	Animation* m_Animation;
	glm::mat4 m_LocalTransform;
};