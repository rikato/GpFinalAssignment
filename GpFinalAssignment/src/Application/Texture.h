#pragma once
#include <glad/glad.h>
#include <string>

class Texture {
private:
	std::string filePath;
	unsigned char* localBuffer;
	int width, height, BPP;
	unsigned int texture;
public:
	Texture(const std::string& path);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void UnBind();

	inline int GetWidth() const { return width; }
	inline int GetHeight() const { return height; }
};