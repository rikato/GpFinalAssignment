#pragma once
#include <string>
#include <unordered_map>

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};


class Shader 
{
private:
	std::string filePath;
	unsigned int rendererId;
	// Chaching uniforms.
	std::unordered_map<std::string, int> uniformLocationCache;
public:
	Shader(const::std::string& filePath);
	~Shader();

	void Bind() const;
	void UnBind() const;

	void SetUniform4f(const std::string& name, float v0, float v1, float f2, float f3);
private:
	unsigned int GetUniformLocation(const std::string& name);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	ShaderProgramSource ParseShader(const std::string& filepath);
};