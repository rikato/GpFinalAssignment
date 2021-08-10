#include "Camera.h"

#include <iostream>

#include "glm/gtc/matrix_transform.hpp"


Camera::Camera(glm::vec3 position, GLFWwindow* window)
	: m_Position((0, 0, 0)), m_Window(nullptr)
{
	m_Position = position;
	m_Window = window;

	m_Projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 10000.0f);
}

Camera::~Camera()
{

}

void Camera::Update()
{
	// Forward (W).
	if (glfwGetKey(m_Window, GLFW_KEY_W) == GLFW_PRESS) 
	{
		m_Position.z += 0.1f;
	}

	// Left (A).
	if (glfwGetKey(m_Window, GLFW_KEY_A) == GLFW_PRESS)
	{
		m_Position.x += 0.1f;
	}

	// Backwards (S).
	if (glfwGetKey(m_Window, GLFW_KEY_S) == GLFW_PRESS)
	{
		m_Position.z -= 0.1f;
	}

	// Right (D).
	if (glfwGetKey(m_Window, GLFW_KEY_D) == GLFW_PRESS)
	{
		m_Position.x -= 0.1f;
	}

	// Starting point is on the street (~1,75m from the ground).
	m_Position.y = 0;

	double mousePosX, mousePosY;

	glfwGetCursorPos(m_Window, &mousePosX, &mousePosY);

	// Update the camera direction based on mouse position.
	MoveCamera(mousePosX, mousePosY);
}

void Camera::MoveCamera(double xPos, double yPos)
{
	if (m_FirstMouse)
	{
		m_LastX = xPos;
		m_LastY = yPos;
		m_FirstMouse = false;
	}

	float xOffset = xPos - m_LastX;
	float yOffset = m_LastY - yPos;

	m_LastX = xPos;
	m_LastY = yPos;

	float sensitivity = 0.1f;

	xOffset *= sensitivity;
	yOffset *= sensitivity;

	m_Yaw += xOffset;
	m_Pitch += yOffset;

	if (m_Pitch > 89.0f) 
	{
		m_Pitch = 89.0f;
	}
	if (m_Pitch < -89.0f) 
	{
		m_Pitch = -89.0f;
	}

	glm::vec3 front;

	front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	front.y = sin(glm::radians(m_Pitch));
	front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	
	m_Front = glm::normalize(front);
}

glm::mat4 Camera::GetProjectionMatrix() const
{
	return m_Projection;
}

glm::mat4 Camera::GetViewMatrix() const
{
	return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}