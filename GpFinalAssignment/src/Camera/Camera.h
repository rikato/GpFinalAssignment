#pragma once 
#include "glm/glm.hpp"
#include <GLFW/glfw3.h>

class Camera {
private:
	// Position of the camera.
	glm::vec3 m_Position;
	// Front direction relative to camera.
	glm::vec3 m_Front = glm::vec3(0.0f, 0.0f, 1.0f);
	// Up direction relative to camera.
	glm::vec3 m_Up = glm::vec3(0.0f, 1.0f, 0.0f);
	// Side direction relative to camera.
	glm::vec3 m_Side = glm::vec3(1.0f, 0.0f, 0.0f);
	glm::mat4 m_Projection;

	GLFWwindow* m_Window;

	float m_Sensitivity = 0.1f;
	float m_KeyboardLookSensitivity = 2.0f;
	float m_MovementSpeed = 3.0f;
	float m_Pitch = 90.0f;
	float m_Yaw = 0.0f;
	float m_LastX = 800.0f / 2.0;
	float m_LastY = 600.0 / 2.0;
	bool m_FirstMouse = true;
	bool m_DroneMode = false;

	void Translate(double deltaTime);
	void Rotate(double xpos, double ypos);
	void RotateUsingKeyboard();
	double* GetMousePositions();
public:
	Camera(glm::vec3 position, GLFWwindow* window);
	~Camera();

	void Update(double deltaTime);

	glm::mat4 GetViewMatrix() const;
	glm::mat4 GetProjectionMatrix() const;
};
