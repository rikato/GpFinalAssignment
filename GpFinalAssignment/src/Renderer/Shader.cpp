#include "Shader.h"

#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Renderer.h"
#include "../vendor/glsl/glsl.h"

Shader::Shader(const::std::string& filePath)
	:filePath(filePath), rendererId(0)
{
	this->rendererId = CreateShader();
}

Shader::~Shader()
{
	GLCall(glDeleteProgram(rendererId));
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
	if (uniformLocationCache.find(name) != uniformLocationCache.end()) 
	{
		return uniformLocationCache[name];
	}

	GLCall(int location = glGetUniformLocation(rendererId, name.c_str()));

	if (location == -1)
	{
		std::cout << "Warning: uniform location does not exist." << std::endl;
	}

	uniformLocationCache[name] = location;

	return location;
}

void Shader::Bind() const
{
	GLCall(glUseProgram(rendererId));
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
