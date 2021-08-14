#include "Object.h"

class Lander : public Object
{
public:
	Lander(glm::vec3 translation = glm::vec3(0, 0, 0)) : Object(
		new Mesh("assets/models/lander/lander.3dobj"), 
		new Shader("assets/shaders/vertex.shader", "assets/shaders/fragmentNormal.shader"),
		new Material())
	{
		Texture* diffuse = new Texture(DIFFUSE, "assets/models/lander/lander.bmp", "diffuseMap", *m_Shader);
		Texture* normal = new Texture(NORMAL, "assets/models/lander/lander_normal.bmp", "normalMap", *m_Shader);

		m_Material->AddTexture(diffuse);
		m_Material->AddTexture(normal);

		m_LocalTransform = glm::translate(m_LocalTransform, translation);
	}
};