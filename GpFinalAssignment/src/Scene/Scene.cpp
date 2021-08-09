#include "Scene.h"
#include "../World/Teapot.h"

Scene::Scene(GLFWwindow *window) 
{
	// Setup the camera.
	this->camera = new Camera(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), window);

	Teapot* teapot1 = new Teapot(glm::vec3(-1, 0, 0));
	Teapot* teapot2 = new Teapot(glm::vec3(1, 0, 0));

	this->objects.push_back(teapot1);
	this->objects.push_back(teapot2);
}

Scene::~Scene()
{
	delete camera;
	delete[] &this->objects;
}
