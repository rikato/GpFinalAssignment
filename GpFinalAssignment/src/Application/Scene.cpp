#include "Scene.h"
#include "Texture.h"
#include "Renderer.h"

Scene::Scene() 
{
	float vertices[16] = 
	{
		-0.5f, -0.5f,	0.0f, 0.0f,
		 0.5f, -0.5f,	1.0f, 0.0f,
		 0.5f,  0.5f,   1.0f, 1.0f,
		-0.5f,  0.5f,	0.0f, 1.0f
	};

	unsigned int indices[6] = {
		0,1,2,
		2,3,0
	};

	va = new VertexArray();
	vb = new VertexBuffer(vertices, 4 * 4 * sizeof(float));
	vbl = new VertexBufferLayout();

	vbl->Push<float>(2);
	vbl->Push<float>(2);
	va->AddBuffer(*vb, *vbl);

	ib = new IndexBuffer(indices, 6);

	Texture texture("res/textures/wall.png");
	
	shader = new Shader("res/shaders/Basic.shader");
	
	shader->Bind();
	shader->SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

	va->UnBind();
	vb->Unbind();
	ib->Unbind();
	shader->UnBind();
}

Scene::~Scene()
{
	vb->~VertexBuffer();
	ib->~IndexBuffer();
	shader->~Shader();
}
