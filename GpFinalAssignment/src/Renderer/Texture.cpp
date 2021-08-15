#include "Texture.h"

#include <glad/glad.h>

#include "../vendor/texture/TextureLoader.h"
#include "../Renderer/Shader.h"

Texture::Texture(TextureType textureType, const std::string& path, const std::string& name, Shader& shader)
{
	m_TextureId = loadBMP(&path[0]);
	m_Slot = (unsigned int)textureType;

	// Set the uniform in the shader.
	shader.SetUniform1i(name, m_TextureId);
	
	// Store the unitform location, so we can activate the texture.
	m_UniformLocation = shader.GetUniformLocation(name);
}

void Texture::SetActive()
{
	// Set the slot as active texture.
	glUniform1i(m_UniformLocation, m_Slot);
	glActiveTexture(GL_TEXTURE0 + m_Slot);
	glBindTexture(GL_TEXTURE_2D, m_TextureId);
}
