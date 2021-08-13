#include "Material.h"
#include "../vendor/texture/Texture.h"
#include <glad/glad.h>

Material::Material(const std::string& diffusePath)
{
	glBindTexture(GL_TEXTURE_2D, 0);

	m_TextureId = loadBMP(&diffusePath[0]);
}

Material::Material(const std::string& diffusePath, const std::string& normalPath)
{
	glBindTexture(GL_TEXTURE_2D, 0);

	m_TextureId = loadBMP(&diffusePath[0]);

	glBindTexture(GL_TEXTURE_2D, 0);

	m_NormalId = loadBMP(&normalPath[0]);
}

