#include "../Object.h"
#include "../Renderer/Material.h"

class UniverseBoard : public Object
{
public:
	UniverseBoard(glm::vec3 translation = glm::vec3(0, 0, 0), glm::vec3 rotation = glm::vec3(0, 0, 0)) : Object(
		new Mesh("assets/models/universeBoard/universeBoard.3dobj"),
		new Shader(""),
		new Material("assets/models/universeBoard/universeBoard.bmp"))
	{
		m_Transform = glm::rotate(m_Transform, rotation.x, glm::vec3(1, 0, 0));
		m_Transform = glm::rotate(m_Transform, rotation.y, glm::vec3(0, 1, 0));
		m_Transform = glm::rotate(m_Transform, rotation.z, glm::vec3(0, 0, 1));
		m_Transform = glm::translate(m_Transform, translation);
	}
};