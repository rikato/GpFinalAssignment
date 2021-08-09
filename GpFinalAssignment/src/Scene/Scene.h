#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "../Renderer/Shader.h"
#include "../Camera/Camera.h"
#include "../World/Object.h"

class Scene
{
public:
	Scene(GLFWwindow* window);
	~Scene();

	std::vector<Object*> m_Objects;
	Camera* m_Camera;
};