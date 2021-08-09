#include "Scene.h"
#include "../World/Teapot.h"

Scene::Scene(GLFWwindow *window) 
{
	// Setup the camera.
	this->camera = new Camera(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), window);

	// Create the teapot.
	Teapot* teapot = new Teapot();

	this->objects.push_back(teapot);
}

Scene::~Scene()
{
	delete camera;
	delete[] &this->objects;
}
