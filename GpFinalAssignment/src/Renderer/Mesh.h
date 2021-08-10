#pragma once
#include <vector>
#include <string>
#include <glad/glad.h>

#include "glm/glm.hpp" 
#include "../Renderer/Shader.h"

class Mesh {
private: 
	unsigned int m_Vao;

	std::vector<glm::vec3> m_Vertices;
	std::vector<glm::vec3> m_Normals;
	std::vector<glm::vec2> m_Uvs;
	char m_DrawingMode = GL_TRIANGLES;

	Shader* m_Shader;

	void Create();
public:
	Mesh(const std::string& path);
	Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec3> normals, std::vector<glm::vec2> uvs, char drawingMode = GL_TRIANGLES);

	void SetShader(Shader* shader);
	void Draw();
};