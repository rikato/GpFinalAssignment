#include "Material.h"

#include <glad/glad.h>

Material::Material()
{

}

void Material::AddTexture(Texture* texture)
{
	m_Textures.push_back(texture);
}
