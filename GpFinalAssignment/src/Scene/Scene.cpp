#include "Scene.h"
#include "../World/MoonSurface.h"
#include "../World/Lander.h"
#include "../World/Cosmonaut.h"
#include "../World/Flag.h"

Scene::Scene(GLFWwindow *window) 
{
	// Setup the camera.
	m_Camera = new Camera(glm::vec3(0, 0, -2), window);

	MoonSurface* moonSurface = new MoonSurface(glm::vec3(0, 0, 0));
	Lander* lander = new Lander(glm::vec3(0, 1.8962, 14));
	Cosmonaut* neil = new Cosmonaut(glm::vec3(0, -0.544038, 9.4171), glm::vec3(0, -37.8824, 0));
	Cosmonaut* buzz = new Cosmonaut(glm::vec3(3.4883, -0.565678, 4.74276), glm::vec3(0, 45, 0));
	Flag* flag = new Flag(glm::vec3(1.81512, -0.512185, 4.74276));

	m_Objects.push_back(moonSurface);
	m_Objects.push_back(lander);
	m_Objects.push_back(neil);
	m_Objects.push_back(buzz);
	m_Objects.push_back(flag);
}

Scene::~Scene()
{
	delete m_Camera;
	delete[] &m_Objects;
}
