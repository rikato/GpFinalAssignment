#pragma once
#include "Scene.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window 
{
public: 
	GLFWwindow* glfwWindow;
	Window();
	~Window();

	void Update();

private:
	Scene* scene;
	//static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
};
