#include "Scene.h"
#include "../World/Teapot.h"
#include "../World/Lander.h"
#include "../World/CosmonautNeil.h"

Scene::Scene(GLFWwindow *window) 
{
	// Setup the camera.
	m_Camera = new Camera(glm::vec3(0, 0, -2), window);

	Teapot* teapot1 = new Teapot(glm::vec3(0, 0, 0));
	Lander* lander = new Lander(glm::vec3(0, 1.8962, 14));
	CosmonautNeil* neil = new CosmonautNeil(glm::vec3(0, 1.8962, 5));

	m_Objects.push_back(teapot1);
	m_Objects.push_back(lander);
	m_Objects.push_back(neil);
}

Scene::~Scene()
{
	delete m_Camera;
	delete[] &m_Objects;
}
