#include "Material.h"
#include "../vendor/texture/Texture.h"

Material::Material(const std::string& diffusePath)
{
	m_TextureId = loadBMP(&diffusePath[0]);
}
