#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Scene.h"
#include "../Renderer/Texture.h"
#include "../Renderer/Renderer.h"

Scene::Scene(GLFWwindow *window) 
{
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
