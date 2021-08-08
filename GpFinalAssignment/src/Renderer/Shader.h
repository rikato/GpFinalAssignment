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
	// Chaching uniforms.
	std::unordered_map<std::string, int> m_UniformLocationCache;
public:
	Shader(const::std::string& filePath);
	~Shader();

	unsigned int m_RendererId;

	void Bind() const;
	void UnBind() const;

	void UpdateMv(glm::mat4 matrix);
	void UpdateProjection(glm::mat4 matrix);
	void SetDiffuseMap(int value);
private:
	unsigned int GetUniformLocation(const std::string& name);
	unsigned int CreateShader();
	void SetUniformMat4f(const std::string& name, glm::mat4 matrix);
	void SetUniform3fv(const std::string& name, glm::vec3 value);
	void SetUniform1i(const std::string& name, int value);
	void SetUniform1f(const std::string& name, float value);
};