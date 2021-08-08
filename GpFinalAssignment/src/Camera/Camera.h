#pragma once 
#include "glm/glm.hpp"
#include <GLFW/glfw3.h>

struct MVP {
	glm::mat4 projection;
	glm::mat4 view;
	glm::mat4 model;
};

class Camera {
private:
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 front;
	glm::vec3 up;
	MVP mvp;

	GLFWwindow* window;
public:
	Camera(glm::vec3 position, glm::vec3 direction, glm::vec3 front, glm::vec3 up, GLFWwindow* window);
	~Camera();

	void Update();
	glm::mat4 GetMVP() const;
};