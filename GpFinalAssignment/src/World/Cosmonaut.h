#include "Object.h"

class Cosmonaut : public Object
{
public:
	Cosmonaut(glm::vec3 translation = glm::vec3(0, 0, 0), glm::vec3 rotation = glm::vec3(0, 0, 0)) : Object(
		new Mesh("assets/models/cosmonauts/cosmonaut.3dobj"),
		new Shader("assets/shaders/vertex.shader", "assets/shaders/fragmentNormal.shader"),
		new Material())
	{
		Texture* diffuse = new Texture(DIFFUSE, "assets/models/cosmonauts/cosmonaut.bmp", "diffuseMap", *m_Shader);
		Texture* normal = new Texture(NORMAL, "assets/models/cosmonauts/comonaut_normal.bmp", "normalMap", *m_Shader);

		m_Material->AddTexture(diffuse);
		m_Material->AddTexture(normal);

		m_LocalTransform = glm::translate(m_LocalTransform, translation);

		m_LocalTransform = glm::rotate(m_LocalTransform, glm::radians(rotation.x), glm::vec3(1, 0, 0));
		m_LocalTransform = glm::rotate(m_LocalTransform, glm::radians(rotation.y), glm::vec3(0, 1, 0));
		m_LocalTransform = glm::rotate(m_LocalTransform, glm::radians(rotation.z), glm::vec3(0, 0, 1));

	}
};