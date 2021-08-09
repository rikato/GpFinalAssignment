#include "Object.h"

class Teapot : public Object 
{
public:
	Teapot(glm::vec3 translation = glm::vec3(0,0,0)): Object(new Mesh("assets/models/teapot/teapot.obj"), new Shader(""))
	{
		this->m_Transform = glm::translate(glm::mat4(1.0), translation);
	}
};