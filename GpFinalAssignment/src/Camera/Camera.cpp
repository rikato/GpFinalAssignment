#include "Camera.h"

#include <iostream>

#include "glm/gtc/matrix_transform.hpp"


Camera::Camera(glm::vec3 position, glm::vec3 direction, glm::vec3 front, glm::vec3 up, GLFWwindow* window)
	: m_Position((0, 0, 0)), m_Direction((0, 0, 0)), m_Front((0, 0, 0)), m_Up((0, 0, 0)), m_Window(nullptr)
{
	m_Position = position;
	m_Direction = direction;
	m_Front = front;
	m_Up = up;
	m_Window = window;

	m_Position.x = 0;
	m_Position.y = 0;
	m_Position.z = -10;

	m_Mvp.projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 10000.0f);
	m_Mvp.view = glm::translate(glm::mat4(1.0), glm::vec3(m_Position));
}

Camera::~Camera()
{

}

void Camera::Update()
{
	// Forward.
	if (glfwGetKey(m_Window, GLFW_KEY_W) == GLFW_PRESS) 
	{
		m_Position.z += 0.1f;
	}

	// Left.
	if (glfwGetKey(m_Window, GLFW_KEY_A) == GLFW_PRESS)
	{
		m_Position.x += 0.1f;
	}

	// Right.
	if (glfwGetKey(m_Window, GLFW_KEY_D) == GLFW_PRESS)
	{
		m_Position.x -= 0.1f;
	}

	// Backwards.
	if (glfwGetKey(m_Window, GLFW_KEY_S) == GLFW_PRESS)
	{
		m_Position.z -= 0.1f;
	}


	m_Mvp.view = glm::translate(glm::mat4(1.0), glm::vec3(m_Position));
}

glm::mat4 Camera::GetViewMatrix() const
{
	return m_Mvp.view;
}

glm::mat4 Camera::GetProjectionMatrix() const
{
	return m_Mvp.projection;
}

