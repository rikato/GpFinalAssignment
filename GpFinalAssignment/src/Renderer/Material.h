#pragma once
#include <string>

class Material 
{
public:
	Material(const std::string &diffusePath);
	Material(const std::string &diffusePath, const std::string& normalPath);

	int m_TextureId;
	int m_NormalId;
};