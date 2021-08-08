#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Scene.h"
#include "../Renderer/Texture.h"
#include "../Renderer/Renderer.h"

Scene::Scene(GLFWwindow *window) 
{
	float vertices[20] = 
	{
		// Positions.			// Texture positions.
		100.0f, 100.0f, 0.0f,	0.0f, 0.0f,
		200.0f, 100.0f,	0.0f,	1.0f, 0.0f,
		200.0f, 200.0f,	0.0f,	1.0f, 1.0f,
		100.0f, 200.0f,	0.0f,	0.0f, 1.0f
	};

	unsigned int indices[6] = {
		0,1,2,
		2,3,0
	};

	va = new VertexArray();
	vb = new VertexBuffer(vertices, 5 * 4 * sizeof(float));
	vbl = new VertexBufferLayout();

	vbl->Push<float>(3);
	vbl->Push<float>(2);
	va->AddBuffer(*vb, *vbl);

	ib = new IndexBuffer(indices, 6);

	// Todo: texture class does not work on certain machines. Don't know why...
	//Texture texture("res/textures/wall.png");
	
	shader = new Shader("assets/shaders/Basic.shader");
	
	shader->Bind();
	shader->SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

	camera = new Camera(glm::vec3(0,0,0), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), window);

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
