#include "Object.h"
#include "../Renderer/Material.h"

class Teapot : public Object 
{
public:
	Teapot(glm::vec3 translation = glm::vec3(0,0,0)): Object(new Mesh("assets/models/teapot/teapot.obj"), new Shader(""), new Material("assets/textures/Yellobrk.bmp"))
	{
		// Set the uniform texture for the shader.
		m_Shader->SetDiffuseMap(m_Material->m_TextureId);
		// Set the position of the object.
		m_Transform = glm::translate(glm::mat4(1.0), translation);
	}
};