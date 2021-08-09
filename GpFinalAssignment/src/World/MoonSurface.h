#include "Object.h"
#include "../Renderer/Material.h"

class MoonSurface : public Object 
{
public:
	MoonSurface(glm::vec3 translation = glm::vec3(0,0,0)): Object(
		new Mesh("assets/models/moon_surface/moon_surface.3dobj"), 
		new Shader(""), 
		new Material("assets/models/moon_surface/moon_surface_base_color.bmp"))
	{
		// Set the position of the object.
		m_Transform = glm::translate(glm::mat4(1.0), translation);
	}
};