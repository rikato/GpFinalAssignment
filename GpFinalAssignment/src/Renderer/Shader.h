#pragma once

#include <string>
#include <unordered_map>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};


class Shader 
{
private:
	std::string m_FilePath;
	unsigned int m_RendererId;
	// Chaching uniforms.
	std::unordered_map<std::string, int> m_UniformLocationCache;
public:
	Shader(const::std::string& filePath);
	~Shader();

	void Bind() const;
	void UnBind() const;

	void updateMv(glm::mat4 matrix);
	void updateProjection(glm::mat4 matrix);
private:
	unsigned int GetUniformLocation(const std::string& name);
	unsigned int CreateShader();
	void SetUniformMat4f(const std::string& name, glm::mat4 matrix);
};