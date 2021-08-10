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

void Camera::Update(double deltaTime)
{
	// Toggle drone mode when user presses 'v'.
	if (glfwGetKey(m_Window, GLFW_KEY_V) == GLFW_PRESS)
	{
		m_DroneMode = !m_DroneMode;
	}

	Translate(deltaTime);

	/* Check wether drone mode is set,
	if it is not set then the y position 
	is fixed, simulating a human pov.
	When it is activated we keep the camera 
	above the floor. */
	if (m_DroneMode) 
	{
		if (m_Position.y < -1.75f) 
		{
			m_Position.y = -1.75f;
		}
	}
	else 
	{
		// Starting point is on the street (~1,75m from the ground).
		m_Position.y = -1.75f;
	}

	double mousePosX, mousePosY;

	glfwGetCursorPos(m_Window, &mousePosX, &mousePosY);
	Rotate(mousePosX, mousePosY);
}

void Camera::Translate(double deltaTime)
{
	const float v = m_MovementSpeed * deltaTime;

	// Forward (W).
	if (glfwGetKey(m_Window, GLFW_KEY_W) == GLFW_PRESS)
	{
		m_Position += m_Front * v;
	}

	// Left (A).
	if (glfwGetKey(m_Window, GLFW_KEY_A) == GLFW_PRESS)
	{
		m_Position -= m_Side * v;
	}

	// Right (D).
	if (glfwGetKey(m_Window, GLFW_KEY_D) == GLFW_PRESS)
	{
		m_Position += m_Side * v;
	}

	// Backwards (S).
	if (glfwGetKey(m_Window, GLFW_KEY_S) == GLFW_PRESS)
	{
		m_Position -= m_Front * v;
	}
}

void Camera::Rotate(double xPos, double yPos)
{
	float xOffset = m_FirstMouse ? 0 : xPos - m_LastX;
	float yOffset = m_FirstMouse ? 0 : m_LastY - yPos;

	if (m_FirstMouse)
	{
		m_FirstMouse = false;
	}

	m_LastX = xPos;
	m_LastY = yPos;

	xOffset *= m_Sensitivity;
	yOffset *= m_Sensitivity;

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

	m_Front = glm::normalize(glm::vec3(
		cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch)),
		sin(glm::radians(m_Pitch)),
		sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch))
	));

	m_Side = glm::normalize(glm::cross(m_Front, m_Up));
}

glm::mat4 Camera::GetProjectionMatrix() const
{
	return m_Projection;
}

glm::mat4 Camera::GetViewMatrix() const
{
	return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}