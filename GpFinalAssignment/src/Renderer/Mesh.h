#pragma once
#include <vector>
#include <string>

#include "glm/glm.hpp" 
#include "../Renderer/Shader.h"

class Mesh {
private: 
	unsigned int m_Vao;

	std::vector<glm::vec3> m_Vertices;
	std::vector<glm::vec3> m_Normals;
	std::vector<glm::vec2> m_Uvs;

	Shader* m_Shader;

	void Create();
public:
	Mesh(const std::string& path);
	Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec3> normals, std::vector<glm::vec2> uvs);

	void SetShader(Shader* shader);
	void Draw();
};