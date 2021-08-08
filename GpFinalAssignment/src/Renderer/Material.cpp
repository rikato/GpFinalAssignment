#include "Material.h"
#include "../vendor/texture/Texture.h"
#include <glad/glad.h>

Material::Material(const std::string& diffusePath)
{
	glBindTexture(GL_TEXTURE_2D, 0);

	m_TextureId = loadBMP(&diffusePath[0]);
}
