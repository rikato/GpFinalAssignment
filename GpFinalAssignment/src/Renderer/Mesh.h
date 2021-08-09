#pragma once
#include <vector>
#include <string>

#include "glm/glm.hpp" 

class Mesh {
private: 
	unsigned int m_Vao;

	std::vector<glm::vec3> m_Vertices;
	std::vector<glm::vec2> m_Normals;
	std::vector<glm::vec3> m_Uvs;

	void Create();
public:
	Mesh(std::string path);

	void Draw();
};