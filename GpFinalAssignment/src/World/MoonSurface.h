#include "Object.h"
#include "../Renderer/Material.h"

class MoonSurface : public Object 
{
public:
	MoonSurface(glm::vec3 translation = glm::vec3(0,0,0)): Object(
		new Mesh("assets/models/moon_surface/moon_surface.3dobj"), 
		new Shader("assets/shaders/vertex.shader", "assets/shaders/fragmentNormal.shader"),
		new Material())
	{
		Texture* diffuse = new Texture(DIFFUSE, "assets/models/moon_surface/moon_surface.bmp", "diffuseMap", *m_Shader);
		Texture* normal = new Texture(NORMAL, "assets/models/moon_surface/moon_surface_normal.bmp", "normalMap", *m_Shader);

		m_Material->AddTexture(diffuse);
		m_Material->AddTexture(normal);

		m_LocalTransform = glm::translate(m_LocalTransform, translation);
	}
};