#include "Scene.h"
#include "../World/MoonSurface.h"
#include "../World/Lander.h"
#include "../World/Cosmonaut.h"
#include "../World/Spotlight.h"
#include "../World/Primitives/Floor.h"
#include "../World/Earth.h"
#include "../World/CustomDesigned/Flag.h"
#include "../World/CustomDesigned/UniverseBoard.h"

Scene::Scene(GLFWwindow *window) 
{
	// Setup the camera.
	m_Camera = new Camera(glm::vec3(0, 0, 0), window);

	// Scene objects (6 uniques).
	//MoonSurface* moonSurface = new MoonSurface(glm::vec3(0, 0.28, 11));
	//Lander* lander = new Lander(glm::vec3(0, 2.49, 14));
	//Cosmonaut* buzz = new Cosmonaut(glm::vec3(2.27, 0.076, 11.49), glm::vec3(0, 0, 0));
	Cosmonaut* neil = new Cosmonaut(glm::vec3(-1.27, 0.076, 10.64), glm::vec3(0, 0, 0));
	//Spotlight* spotlightLeft = new Spotlight(glm::vec3(-1.3, 0, 4.7), glm::vec3(0, 0, 0));
	//Spotlight* spotlightRight = new Spotlight(glm::vec3(1.3, 0, 4.7), glm::vec3(0, 0, 0));
	//
	//Tripod* tripod = new Tripod(glm::vec3(0, 0, 0));
    //FilmCamera* camera = new FilmCamera(glm::vec3(0, 0, 0));
 
	// Custom designed objects (5 uniques).
	// TODO: add 3-4 designed object files.

	//Flag* flag = new Flag(glm::vec3(0, 1, 9.12));
	//UniverseBoard* universeBoard = new UniverseBoard(glm::vec3(0, 3, 17), glm::vec3(0, 0, 0));
	// SupportPlank* supportPlank1 = new SupportPlank(glm::vec3(0, 0, 0));
	// SupportPlank* supportPlank2 = new SupportPlank(glm::vec3(0, 0, 0));
	// SupportPlank* supportPlank3 = new SupportPlank(glm::vec3(0, 0, 0));
	// DirectorChair* directorChair = new DirectorChair(glm::vec3(0, 0, 0));
	// MovieClapper* movieClapper = new MovieClapper(glm::vec3(0, 0, 0));
	// MovieClapper* movieClapper = new MovieClapper(glm::vec3(0, 0, 0));
	// VoiceCone* voiceCone = new VoiceCone(glm::vec3(0, 0, 0));

	// Custom primitive meshes (4).
	// TODO: add 4-6 primative meshes.
	 //Floor* floor = new Floor(glm::vec3(-0.5, 0, -0.1));
	// The earth is a disc since the earth is actually flat.
	 //Earth* earth= new Earth(glm::vec3(4, 4, 16));
	// FakeEarthString* fakeEarthString = new FakeEarthString(glm::vec3(0, 0, 0));

	//m_Objects.push_back(moonSurface);
	//m_Objects.push_back(lander);
	m_Objects.push_back(neil);
	//m_Objects.push_back(buzz);
	/*m_Objects.push_back(spotlightLeft);
	m_Objects.push_back(spotlightRight);*/

	//m_Objects.push_back(flag);
	//m_Objects.push_back(universeBoard);
	//
	//m_Objects.push_back(floor);
	//m_Objects.push_back(earth);
}

Scene::~Scene()
{
	delete m_Camera;
	delete[] &m_Objects;
}
