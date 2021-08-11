#pragma once
#include <string>

class Material 
{
public:
	Material(const std::string &diffusePath);

	int m_TextureId;
};