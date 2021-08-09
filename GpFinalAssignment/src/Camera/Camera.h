#pragma once 
#include "glm/glm.hpp"
#include <GLFW/glfw3.h>

struct MVP {
	glm::mat4 projection;
	glm::mat4 view;
};

class Camera {
private:
	glm::vec3 m_Position;
	glm::vec3 m_Direction;
	glm::vec3 m_Front;
	glm::vec3 m_Up;
	MVP m_Mvp;

	GLFWwindow* m_Window;
public:
	Camera(glm::vec3 position, glm::vec3 direction, glm::vec3 front, glm::vec3 up, GLFWwindow* window);
	~Camera();

	void Update();
	glm::mat4 GetViewMatrix() const;
	glm::mat4 GetProjectionMatrix() const;
};