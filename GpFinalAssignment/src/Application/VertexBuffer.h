#pragma once
#include <glad/glad.h>

class VertexBuffer
{
private:
	unsigned int rendererId;
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;
};