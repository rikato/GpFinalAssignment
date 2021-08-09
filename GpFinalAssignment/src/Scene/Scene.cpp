#include "Scene.h"
#include "../Helpers/Mesh.h"

Scene::Scene(GLFWwindow *window) 
{
	// Setup the camera.
	this->camera = new Camera(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), window);

	// Create the teapot.
	Shader* teapotShader = new Shader("");
	Mesh* teapotMesh = new Mesh("assets/models/teapot/teapot.obj");
	Object* teapot = new Object(teapotMesh, teapotShader);

	this->objects.push_back(teapot);
}

Scene::~Scene()
{
	delete camera;
	delete[] &this->objects;
}
