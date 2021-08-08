#include "Camera.h"

#include <iostream>

#include "glm/gtc/matrix_transform.hpp"


Camera::Camera(glm::vec3 position, glm::vec3 direction, glm::vec3 front, glm::vec3 up, GLFWwindow* window)
	: position((0, 0, 0)), direction((0, 0, 0)), front((0, 0, 0)), up((0, 0, 0)), window(nullptr)
{
	this->position = position;
	this->direction = direction;
	this->front = front;
	this->up = up;
	this->window = window;

	this->position.x = -150;
	this->position.y = -20;
	this->position.z = -1000;

	this->mvp.projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 10000.0f);
	this->mvp.view = glm::translate(glm::mat4(1.0), glm::vec3(this->position));
	this->mvp.model = glm::translate(glm::mat4(1.0), glm::vec3(0.0f, 0.0f, 0.0f));
}

Camera::~Camera()
{

}

void Camera::Update()
{
	// Forward.
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) 
	{
		this->position.z += 1;
	}

	// Left.
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		this->position.x += 1;
	}

	// Right.
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		this->position.x -= 1;
	}

	// Backwards.
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		this->position.z -= 1;
	}


	this->mvp.view = glm::translate(glm::mat4(1.0), glm::vec3(this->position));
}

glm::mat4 Camera::GetMVP() const
{
	return mvp.projection * mvp.view * mvp.model;
}

