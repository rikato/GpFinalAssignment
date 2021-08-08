#include "Object.h"
#include "../Renderer/Material.h"

class Teapot : public Object 
{
public:
	Teapot(glm::vec3 translation = glm::vec3(0,0,0)): Object(
		new Mesh("assets/models/moon_surface/moon_surface.obj"), 
		new Shader(""), 
		new Material("assets/models/moon_surface/moon_surface_base_color"))
	{
		// Set the position of the object.
		m_Transform = glm::translate(glm::mat4(1.0), translation);
	}
};