#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../Scene/Scene.h"

class Application 
{
public:
	Application();
	~Application();

	void Start();

private: 
	GLFWwindow* glfwWindow;
	Scene* scene;
};
