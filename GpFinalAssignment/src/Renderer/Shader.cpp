#include "Shader.h"

#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <glm/gtc/type_ptr.hpp>

#include "Renderer.h"
#include "../vendor/glsl/glsl.h"

Shader::Shader(const::std::string& filePath)
	:m_FilePath(filePath), m_RendererId(0)
{
	m_RendererId = CreateShader();
}

Shader::~Shader()
{
	GLCall(glDeleteProgram(m_RendererId));
}

unsigned int Shader::CreateShader()
{
	unsigned int program = glCreateProgram();

	char* vs = glsl::readFile("assets/shaders/vertexshader.shader");
	char* fs = glsl::readFile("assets/shaders/fragmentshader.shader");

	unsigned int vsId = glsl::makeVertexShader(vs);
	unsigned int fsId = glsl::makeFragmentShader(fs);

	// Attach the shaders to the program.
	glAttachShader(program, vsId);
	glAttachShader(program, fsId);
	glLinkProgram(program);
	glValidateProgram(program);

	// Program is linked so we can delete the shaders.
	glDeleteShader(vsId);
	glDeleteShader(fsId);

	return program;
}

void Shader::SetUniformMat4f(const std::string& name, glm::mat4 matrix)
{
	unsigned int location = GetUniformLocation(name);

	GLCall(glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]));
}

void Shader::SetUniform3fv(const std::string& name, glm::vec3 value)
{
	unsigned int location = GetUniformLocation(name);

	glUniform3fv(location, 1, &value[0]);
}

void Shader::SetUniform1i(const std::string& name, int value)
{
	unsigned int location = GetUniformLocation(name);

	glUniform1i(location, value);
}

void Shader::SetUniform1f(const std::string& name, float value)
{
	unsigned int location = GetUniformLocation(name);

	glUniform1f(location, value);
}

unsigned int Shader::GetUniformLocation(const std::string& name)
{
	if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end()) 
	{
		return m_UniformLocationCache[name];
	}

	GLCall(int location = glGetUniformLocation(m_RendererId, name.c_str()));

	if (location == -1)
	{
		std::cout << "Warning: uniform location does not exist." << std::endl;
	}

	m_UniformLocationCache[name] = location;

	return location;
}

void Shader::Bind() const
{
	GLCall(glUseProgram(m_RendererId));
}

void Shader::UnBind() const
{
	GLCall(glUseProgram(0));
}

void Shader::UpdateMv(glm::mat4 matrix)
{
	SetUniformMat4f("mv", matrix);

	SetUniform3fv("materialAmbientColor", glm::vec3(0.0, 0.0, 0.1));
	SetUniform3fv("materialDiffuseColor", glm::vec3(1.3, 1.3, 1.3));
	SetUniform3fv("materialSpecularColor", glm::vec3(1, 1, 1));
	SetUniform1f("materialRoughness", 1024);
}

void Shader::UpdateProjection(glm::mat4 matrix)
{
	SetUniformMat4f("projection", matrix);
}

void Shader::SetDiffuseMap(int value)
{
	SetUniform1i("diffuseMap", value);
	SetUniform1i("normalMap", value);
}