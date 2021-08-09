#include "Shader.h"

#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>

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

	char* vs = glsl::readFile("assets/shaders/basic.vert");
	char* fs = glsl::readFile("assets/shaders/basic.frag");

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
	unsigned int location = this->GetUniformLocation(name);

	GLCall(glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]));
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

void Shader::updateMv(glm::mat4 matrix)
{
	this->SetUniformMat4f("mv", matrix);
}

void Shader::updateProjection(glm::mat4 matrix)
{
	this->SetUniformMat4f("projection", matrix);
}
