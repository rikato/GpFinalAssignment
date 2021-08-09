#pragma once
#include "VertexBuffer.h"

class VertexBufferLayout;

#include <glad/glad.h>

class VertexArray 
{
private:
	unsigned int rendererId;
	
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
	void Bind() const;
	void UnBind() const;
	int GetRendererId() const;
};