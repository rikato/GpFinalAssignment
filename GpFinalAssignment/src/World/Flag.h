#include "Object.h"
#include "../Renderer/Material.h"

class Flag : public Object
{
public:
	Flag(glm::vec3 translation = glm::vec3(0, 0, 0), glm::vec3 rotation = glm::vec3(0, 0, 0)) : Object(
		new Mesh("assets/models/flag/flag.obj"),
		new Shader(""),
		new Material("assets/models/flag/soviet_flag.bmp"))
	{
		m_Transform = glm::translate(glm::mat4(1.0), translation);
		m_Transform = glm::rotate(m_Transform, rotation.x, glm::vec3(1, 0, 0));
		m_Transform = glm::rotate(m_Transform, rotation.y, glm::vec3(0, 1, 0));
		m_Transform = glm::rotate(m_Transform, rotation.z, glm::vec3(0, 0, 1));
	}
};