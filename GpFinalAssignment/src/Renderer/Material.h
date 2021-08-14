#pragma once
#include <string>
#include <vector>

#include "../Renderer/Shader.h"
#include "../Renderer/Texture.h"

class Material 
{
public:
	Material();

	~Material() { std::cout << "dead mat" << std::endl; }

	std::vector<Texture*> m_Textures;

	void AddTexture(Texture* texture);
};