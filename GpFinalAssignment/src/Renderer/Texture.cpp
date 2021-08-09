#include "Texture.h"

#include <iostream>

#include "stb_image/stb_image.h"

#include "Renderer.h"

Texture::Texture(const std::string& path)
	: filePath(path), localBuffer(nullptr), 
	width(0), height(0), BPP(0)
{
	// Flip the texture, so it's upside down.
	stbi_set_flip_vertically_on_load(1);
	localBuffer = stbi_load(path.c_str(), &width, &height, &BPP, 4);

	GLCall((1, 0));
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));

	// These 4 params need to specified!
	GLCall(glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GLCall(glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GLCall(glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP));
	GLCall(glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP));

	GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer));
	GLCall(glGenerateMipmap(GL_TEXTURE_2D));
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));

	if (localBuffer) 
	{
		stbi_image_free(localBuffer);
	}
	else 
	{
		std::cout << "Failed to load texture" << std::endl;
	}
}

Texture::~Texture()
{
	//glDeleteTextures(1, 0);
}

void Texture::Bind(unsigned int slot) const
{
	GLCall(glActiveTexture(GL_TEXTURE0 + slot));
	GLCall(glBindTexture(GL_TEXTURE_2D, texture));
}

void Texture::UnBind()
{
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}