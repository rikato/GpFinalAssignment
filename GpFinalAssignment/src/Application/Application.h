#pragma once

#ifndef APPLICATION_H
#define APPLICATION_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

const float SCREEN_WIDTH = 1600.0f;
const float SCREEN_HEIGHT = 900.0f;

class Application 
{
public:
	Application();
	~Application();

	void Start();
private:
	GLFWwindow* m_GlfwWindow;
};

#endif 