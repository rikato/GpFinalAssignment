#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../Helpers/IndexBuffer.h"
#include "../Helpers/VertexBuffer.h"
#include "../Helpers/VertexArray.h"
#include "../Helpers/VertexBufferLayout.h"
#include "../Renderer/Shader.h"
#include "../Camera/Camera.h"

class Scene
{
public:
	Scene(GLFWwindow* window);
	~Scene();
	VertexArray* va;
	IndexBuffer* ib;
	Shader* shader;
	Camera* camera;

private:
	VertexBufferLayout* vbl;
	VertexBuffer* vb;
};