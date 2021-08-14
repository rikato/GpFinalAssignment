#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "../Renderer/Shader.h"
#include "../Camera/Camera.h"
#include "../World/Object.h"
#include "../World/Model.h"

class Scene
{
private:
	std::vector<Model*> m_Models;
public:
	Scene(GLFWwindow* window);
	~Scene();

	Camera* m_Camera;

	const std::vector<Model*> GetModels();
};