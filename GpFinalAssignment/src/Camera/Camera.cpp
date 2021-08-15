#include "../Application/Application.h"
#include "Camera.h"
#include <iostream>
#include "glm/gtc/matrix_transform.hpp"

Camera::Camera(glm::vec3 position, GLFWwindow* window)
	: m_Position((0, 0, 0)), m_Window(nullptr)
{
	m_Position = position;
	m_Window = window;

	m_Projection = glm::perspective(glm::radians(45.0f), SCREEN_WIDTH  / SCREEN_HEIGHT, 0.1f, 10000.0f);
}

Camera::~Camera()
{

}

double* Camera::GetMousePositions()
{
	double mousePosX, mousePosY;

	glfwGetCursorPos(m_Window, &mousePosX, &mousePosY);

	double result[2] = { mousePosX, mousePosY };

	return &result[0];
}

void Camera::DroneModeState()
{
	if (!m_DroneMode && m_PressedV && glfwGetKey(m_Window, GLFW_KEY_V) == GLFW_RELEASE)
	{
		m_DroneMode = true;
		m_PressedV = false;

		// Give the camera a nice overview of the scene.
		m_LastPosition = m_Position;
		m_Position = glm::vec3(-3, 8, -6);
		m_Pitch = -35;
		m_Yaw = 75;
	}

	if (m_DroneMode && m_PressedV && glfwGetKey(m_Window, GLFW_KEY_V) == GLFW_RELEASE)
	{
		m_DroneMode = false;
		m_PressedV = false;

		// Return to latest location when drone mode gets disabled.
		m_Position = m_LastPosition;
	}

	// Check wether user wants to toggle drone mode by pressing 'v'.
	if (!m_PressedV && glfwGetKey(m_Window, GLFW_KEY_V) == GLFW_PRESS)
	{
		m_PressedV = true;
	}
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

void Camera::RotateUsingKeyboard()
{
	// Look up (I).
	if (glfwGetKey(m_Window, GLFW_KEY_I) == GLFW_PRESS)
	{
		m_LastY += m_KeyboardLookSensitivity;
	}

	// Look left (J).
	if (glfwGetKey(m_Window, GLFW_KEY_J) == GLFW_PRESS)
	{
		m_LastX += m_KeyboardLookSensitivity;
	}

	// Look right (L).
	if (glfwGetKey(m_Window, GLFW_KEY_L) == GLFW_PRESS)
	{
		m_LastX -= m_KeyboardLookSensitivity;
	}

	// Look down (K).
	if (glfwGetKey(m_Window, GLFW_KEY_K) == GLFW_PRESS)
	{
		m_LastY -= m_KeyboardLookSensitivity;
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

void Camera::Update(double deltaTime)
{
	DroneModeState();

	// Check for level boundries.
	if (m_DroneMode)
	{
		// When camera goes below the map reset it's position to '0'.
		if (m_Position.y < 0.5)
		{
			m_Position.y = 0.5;
		}
	}
	else
	{
		// Starting point is on the street (~1,75m from the ground).
		m_Position.y = 1.75f;
	}

	// Translate the camera position based on keyboard intput (WASD).
	Translate(deltaTime);

	// Get the position of the cursor, we use this to rotate the camera.
	double *cursorPosition = GetMousePositions();

	// Rotate camere based on x, y position of the mouse.
	Rotate(cursorPosition[0], cursorPosition[1]);

	// Update last x and last y positions based on keyboard input (IJKL).
	RotateUsingKeyboard();
}


glm::mat4 Camera::GetProjectionMatrix() const
{
	return m_Projection;
}

glm::mat4 Camera::GetViewMatrix() const
{
	return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}