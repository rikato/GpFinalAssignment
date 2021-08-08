#include "Scene.h"
#include "Texture.h"
#include "Renderer.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

Scene::Scene() 
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
	
	shader = new Shader("res/shaders/Basic.shader");
	
	shader->Bind();
	shader->SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

	glm::mat4 proj = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 2000.0f);;
	glm::mat4 view = glm::translate(glm::mat4(1.0), glm::vec3(-150.0f, -20.0f, -800.0f));
	glm::mat4 model = glm::translate(glm::mat4(1.0), glm::vec3(0.0f, 0.0f, 0.0f));
	model = glm::rotate(model, glm::radians(45.f), glm::vec3(1.0f, 1.0f, 1.0f));

	glm::mat4 mvp = proj * view * model;

	shader->Bind();
	shader->SetUniformMat4f("MVP", mvp);

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
