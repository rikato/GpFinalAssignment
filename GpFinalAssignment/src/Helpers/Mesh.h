#pragma once
#include <vector>
#include <string>

#include "glm/glm.hpp" 

class Mesh {
private: 
	unsigned int vao;

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> normals;
	std::vector<glm::vec3> uvs;

	void Create();
public:
	Mesh(std::string path);

	void Draw();
};