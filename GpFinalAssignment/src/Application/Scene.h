#pragma once
#include <glad/glad.h>
#include "IndexBuffer.h"
#include "VertexBuffer.h"

class Scene
{
public:
	Scene();
	~Scene();

private: 
	VertexBuffer* vb;
	IndexBuffer* ib;
};