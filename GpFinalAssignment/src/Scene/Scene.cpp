#include "Scene.h"
#include "../World/MoonSurface.h"
#include "../World/Lander.h"
#include "../World/Cosmonaut.h"
#include "../World/PulledCosmonaut.h"
#include "../World/Spotlight.h"
#include "../World/Primitives/Floor.h"
#include "../World/Primitives/Earth.h"
#include "../World/Primitives/Rope.h"
#include "../World/Primitives/Crate.h"
#include "../World/Primitives/NuclearWasteSign.h"
#include "../World/CustomDesigned/Flag.h"
#include "../World/CustomDesigned/UniverseBoard.h"
#include "../World/CustomDesigned/WetFloorSign.h"
#include "../World/CustomDesigned/MovieClapper.h"

Scene::Scene(GLFWwindow *window) 
{
	// Setup the camera.
	m_Camera = new Camera(glm::vec3(0, 0, 0), window);

	// Scene objects (6 uniques).
	//MoonSurface* moonSurface = new MoonSurface(glm::vec3(0, 0.28, 0));
	Lander* lander = new Lander(glm::vec3(0, 2.49, 3));
	PulledCosmonaut* buzz = new PulledCosmonaut(glm::vec3(1.27, 0.07, 0), glm::vec3(0, 45, 0));
	Cosmonaut* neil = new Cosmonaut(glm::vec3(-1.27, 0.07, 0));
	Spotlight* spotlightLeft = new Spotlight(glm::vec3(-1.3, 0, -5.7));
	Spotlight* spotlightRight = new Spotlight(glm::vec3(1.3, 0, -5.7));
	//Tripod* tripod = new Tripod(glm::vec3(0, 0, 0));
    //FilmCamera* camera = new FilmCamera(glm::vec3(0, 0, 0));
 
	// Custom designed objects (5 uniques).
	Flag* flag = new Flag(glm::vec3(0, .5, -0.5));
	UniverseBoard* universeBoard = new UniverseBoard(glm::vec3(0, 3, 0));
	WetFloorSign* wetFloorSign = new WetFloorSign(glm::vec3(-4, 0.434748, 0), glm::vec3(0, -45, 0));
	MovieClapper* movieClapper = new MovieClapper(glm::vec3(0, 0.202, 0));
	// SupportPlank* supportPlank1 = new SupportPlank(glm::vec3(0, 0, 0));
	// SupportPlank* supportPlank2 = new SupportPlank(glm::vec3(0, 0, 0));
	// SupportPlank* supportPlank3 = new SupportPlank(glm::vec3(0, 0, 0));
	// DirectorChair* directorChair = new DirectorChair(glm::vec3(0, 0, 0));
	// VoiceCone* voiceCone = new VoiceCone(glm::vec3(0, 0, 0));

	// Custom primitive meshes (4).
	Floor* floor = new Floor();
	Earth* earth= new Earth(glm::vec3(4, 1.5, -0.5));
	Rope* rope = new Rope(glm::vec3(0, 2, -0.4), glm::vec3(90, 0, 0));
	Crate* crate1 = new Crate(glm::vec3(1, 1, -0.6), glm::vec3(0, 45, 0));
	Crate* crate2 = new Crate(glm::vec3(-1, 1, -1.2), glm::vec3(0, 45, 0));
	Crate* crate3 = new Crate(glm::vec3(0, 3, -0.3), glm::vec3(0, 45, 0));
	NuclearWasteSign* nuclearWasteSign = new NuclearWasteSign(glm::vec3(0, 3, -1.4), glm::vec3(0, 45, 0));

	// The whole set that is staging the moon landing.
	Model* moonLandingSet = new Model({  lander, buzz, neil, spotlightLeft, spotlightRight, flag }, glm::vec3(0, 0, 11));

	// The fake earth hanging from the roof consisting of 4 primitve meshes.
	Model* fakeUniverse = new Model({ universeBoard, rope, earth }, glm::vec3(0, 0, 20));
	
	Model* crates = new Model({ crate1, crate2, crate3, rope, nuclearWasteSign, wetFloorSign }, glm::vec3(10, 0, 16));

	// The floor of the scene
	Model* woodenFloor = new Model({ floor }, glm::vec3(-15, 0, -0.1));

	Model* DirectorAndCamera = new Model({ movieClapper }, glm::vec3(0, 0, 4));

	m_Models.push_back(moonLandingSet);
	m_Models.push_back(fakeUniverse);
	m_Models.push_back(woodenFloor);
	m_Models.push_back(crates);
}

Scene::~Scene()
{
	delete m_Camera;
	delete[] &m_Models;
}

const std::vector<Model*> Scene::GetModels()
{
	return m_Models;
}
