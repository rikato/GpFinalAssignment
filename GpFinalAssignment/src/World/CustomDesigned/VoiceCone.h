#include "../Object.h"
#include "../Renderer/Material.h"

class VoiceCone : public Object
{
public:
	VoiceCone(glm::vec3 translation = glm::vec3(0, 0, 0), glm::vec3 rotation = glm::vec3(0, 0, 0)) : Object(
		new Mesh("assets/models/voice_cone/voice_cone.3dobj"),
		new Shader("assets/shaders/vertex.shader", "assets/shaders/fragment.shader"),
		new Material())
	{
		Texture* diffuse = new Texture(DIFFUSE, "assets/models/voice_cone/voice_cone.bmp", "diffuseMap", *m_Shader);

		m_Material->AddTexture(diffuse);

		m_LocalTransform = glm::rotate(m_LocalTransform, rotation.x, glm::vec3(1, 0, 0));
		m_LocalTransform = glm::rotate(m_LocalTransform, rotation.y, glm::vec3(0, 1, 0));
		m_LocalTransform = glm::rotate(m_LocalTransform, rotation.z, glm::vec3(0, 0, 1));

		m_LocalTransform = glm::translate(m_LocalTransform, translation);
	}
};