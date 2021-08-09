#pragma once
#include "glm/glm.hpp" 
#include "../Helpers/Mesh.h" 

class Object {
public:
	Mesh mesh;
	glm::mat4 transform;
};