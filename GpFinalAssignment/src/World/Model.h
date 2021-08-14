#pragma once

#include <vector>

#include "Object.h"

class Model 
{
private:
	std::vector<Object*> m_Objects;
public:
	Model(std::vector<Object*> objects, glm::vec3 translation = glm::vec3(0, 0, 0));
	void Update(glm::mat4 viewMatrix, glm::mat4 projectionMatrix, double deltaTime);

	glm::mat4 m_GloablTransform;
};