#pragma once
#include "glm/glm.hpp" 
#include "../Helpers/Mesh.h" 
#include "../Renderer/Shader.h"

class Object {
public:
	Object(Mesh* mesh, Shader* shader);
	~Object();

	void Update(glm::mat4 mvMatrix, glm::mat4 projectionMatrix);

	Mesh* mesh;
	Shader* shader;
	glm::mat4 transform;
};