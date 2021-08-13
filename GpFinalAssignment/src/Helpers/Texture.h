#pragma once

#include <string>
#include <iostream>

#include "../Renderer/Shader.h"

enum TextureType
{
	DIFFUSE,
	NORMAL
};

class Texture
{
private:
	unsigned int m_TextureId;
	unsigned int m_Slot;
	unsigned int m_UniformLocation;

public: 
	Texture(TextureType textureType, const std::string& path, const std::string& name, Shader& shader);

	~Texture() { std::cout << "dead" << m_TextureId << std::endl; }

	void SetActive();
};