#include "Object.h"
#include "../Renderer/Material.h"

class Lander : public Object
{
public:
	Lander(glm::vec3 translation = glm::vec3(0, 0, 0)) : Object(
		new Mesh("assets/models/lander/lander.3dobj"), 
		new Shader(""), 
		new Material("assets/models/lander/lander.bmp"))
	{
		m_Transform = glm::rotate(m_Transform, glm::radians(-147.0f), glm::vec3(0, 1, 0));
		m_Transform = glm::translate(glm::mat4(1.0), translation);
	}
};