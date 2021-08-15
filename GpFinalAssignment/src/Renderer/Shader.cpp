#include "Shader.h"

#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <glm/gtc/type_ptr.hpp>

#include "Renderer.h"
#include "../vendor/glsl/glsl.h"

Shader::Shader(const std::string& filePathVertex, const std::string& filePathFragment)
	: m_RendererId(0)
{
	unsigned int program = glCreateProgram();

	// Load the shaders.
	char* vs = glsl::readFile(&filePathVertex[0]);
	char* fs = glsl::readFile(&filePathFragment[0]);

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

	m_RendererId = program;
}

Shader::~Shader()
{
	glDeleteProgram(m_RendererId);
}

unsigned int Shader::GetUniformLocation(const std::string& name)
{
	// If the uniform is already looked ip, wo don't want to search for it again.
	// Instead we wil just get the uniform location from the uniformLocations map and return it.
	if (m_UniformLocations.find(name) != m_UniformLocations.end())
	{
		return m_UniformLocations[name];
	}

	int location = glGetUniformLocation(m_RendererId, name.c_str());

	if (location == -1)
	{
		std::cout << "Uniform location not found." << std::endl;
	}

	// Add the location to the uniformLocations so it can be used next time wel look for the same uniform.
	m_UniformLocations[name] = location;

	return location;
}

void Shader::Bind() const
{
	// Bind program, this is used every frame.
	glUseProgram(m_RendererId);
}

void Shader::UpdateMv(glm::mat4 matrix)
{
	SetUniform<glm::mat4>("mv", matrix);
}

void Shader::UpdateProjection(glm::mat4 matrix)
{
	SetUniform<glm::mat4>("projection", matrix);
}

