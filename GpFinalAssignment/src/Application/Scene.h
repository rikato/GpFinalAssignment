#pragma once
#include <glad/glad.h>
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Shader.h"

class Scene
{
public:
	Scene();
	~Scene();
	VertexArray* va;
	IndexBuffer* ib;
	Shader* shader;

private:
	VertexBufferLayout* vbl;
	VertexBuffer* vb;
};