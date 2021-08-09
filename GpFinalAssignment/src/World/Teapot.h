#include "Object.h"

class Teapot : public Object 
{
public:
	Teapot(): Object(new Mesh("assets/models/teapot/teapot.obj"), new Shader(""))
	{
		this->transform = glm::translate(glm::mat4(1.0), glm::vec3(-1, 0, 0));
	}
};