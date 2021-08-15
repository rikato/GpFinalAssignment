#pragma once

#include <string>
#include <unordered_map>

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Shader 
{
private:
	// This is used to store all uniform locations.
	std::unordered_map<std::string, int> m_UniformLocations;
public:
	Shader(const std::string& filePathVertex, const std::string& filePathFragment);
	~Shader();

	unsigned int m_RendererId;

	unsigned int GetUniformLocation(const std::string& name);

	void Bind() const;
	void UpdateMv(glm::mat4 matrix);
	void UpdateProjection(glm::mat4 matrix);

	template<typename T>
	void SetUniform(const std::string& name, T data)
	{

	}

	template<>
	void SetUniform<glm::mat4>(const std::string& name, glm::mat4 data)
	{
		unsigned int location = GetUniformLocation(name);

		glUniformMatrix4fv(location, 1, GL_FALSE, &data[0][0]);
	}

	template<>
	void SetUniform<glm::vec3>(const std::string& name, glm::vec3 data)
	{
		unsigned int location = GetUniformLocation(name);

		glUniform3fv(location, 1, &data[0]);
	}


	template<>
	void SetUniform<int>(const std::string& name, int data)
	{
		unsigned int location = GetUniformLocation(name);

		glUniform1i(location, data);
	}

	template<>
	void SetUniform<float>(const std::string& name, float data)
	{
		unsigned int location = GetUniformLocation(name);

		glUniform1f(location, data);
	}
};