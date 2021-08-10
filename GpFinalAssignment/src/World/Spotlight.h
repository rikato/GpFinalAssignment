#include "Object.h"
#include "../Renderer/Material.h"

class Spotlight : public Object
{
public:
	Spotlight(glm::vec3 translation = glm::vec3(0, 0, 0), glm::vec3 rotation = glm::vec3(0, 0, 0)) : Object(
		new Mesh("assets/models/spotlight/spotlight.3dobj"),
		new Shader(""),
		new Material("assets/models/spotlight/spotlight.bmp"))
	{
		m_Transform = glm::rotate(m_Transform, rotation.x, glm::vec3(1, 0, 0));
		m_Transform = glm::rotate(m_Transform, rotation.y, glm::vec3(0, 1, 0));
		m_Transform = glm::rotate(m_Transform, rotation.z, glm::vec3(0, 0, 1));
		m_Transform = glm::translate(glm::mat4(1.0), translation);
	}
};