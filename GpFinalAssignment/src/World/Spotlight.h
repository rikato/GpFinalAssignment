#include "Object.h"
#include "../Renderer/Material.h"

class Spotlight : public Object
{
public:
	Spotlight(glm::vec3 translation = glm::vec3(0, 0, 0), glm::vec3 rotation = glm::vec3(0, 0, 0)) : Object(
		new Mesh("assets/models/spotlight/spotlight.3dobj"),
		new Shader("assets/shaders/vertex.shader", "assets/shaders/fragmentNormal.shader"),
		new Material())
	{
		Texture* diffuse = new Texture(DIFFUSE, "assets/models/spotlight/spotlight.bmp", "diffuseMap", *m_Shader);
		Texture* normal = new Texture(NORMAL, "assets/models/spotlight/spotlight_normal.bmp", "normalMap", *m_Shader);
		
		m_Material->AddTexture(diffuse);
		m_Material->AddTexture(normal);

		m_Transform = glm::rotate(m_Transform, rotation.x, glm::vec3(1, 0, 0));
		m_Transform = glm::rotate(m_Transform, rotation.y, glm::vec3(0, 1, 0));
		m_Transform = glm::rotate(m_Transform, rotation.z, glm::vec3(0, 0, 1));
		m_Transform = glm::translate(glm::mat4(1.0), translation);
	}
};