#include "../Object.h"
#include "../Renderer/Material.h"

class Flag : public Object
{
public:
	Flag(glm::vec3 translation = glm::vec3(0, 0, 0), glm::vec3 rotation = glm::vec3(0, 0, 0)) : Object(
		new Mesh("assets/models/flag/flag.3dobj"),
		new Shader("assets/shaders/vertex.shader", "assets/shaders/fragment.shader"),
		new Material())
	{
		Texture* diffuse = new Texture(DIFFUSE, "assets/models/flag/flag.bmp", "diffuseMap", *m_Shader);

		m_Material->AddTexture(diffuse);

		m_Transform = glm::rotate(m_Transform, rotation.x, glm::vec3(1, 0, 0));
		m_Transform = glm::rotate(m_Transform, rotation.y, glm::vec3(0, 1, 0));
		m_Transform = glm::rotate(m_Transform, rotation.z, glm::vec3(0, 0, 1));
		m_Transform = glm::translate(glm::mat4(1.0), translation);
	}
};