#include "../Object.h"
#include "../Renderer/Material.h"

class Flag : public Object
{
public:
	Flag(glm::vec3 translation = glm::vec3(0, 0, 0), glm::vec3 rotation = glm::vec3(0, 0, 0)) : Object(
		new Mesh("assets/models/flag/flag.3dobj"),
		new Shader("assets/shaders/vertex.shader", "assets/shaders/fragment.shader"),
		new Material(),
		new Animation())
	{
		Texture* diffuse = new Texture(DIFFUSE, "assets/models/flag/flag.bmp", "diffuseMap", *m_Shader);

		m_Material->AddTexture(diffuse);

		m_LocalTransform = glm::rotate(m_LocalTransform, rotation.x, glm::vec3(1, 0, 0));
		m_LocalTransform = glm::rotate(m_LocalTransform, rotation.y, glm::vec3(0, 1, 0));
		m_LocalTransform = glm::rotate(m_LocalTransform, rotation.z, glm::vec3(0, 0, 1));
		m_LocalTransform = glm::translate(m_LocalTransform, translation);

		m_Animation->SetLocalTransform(m_LocalTransform);

		// A waving flag animation.
		m_Animation->AddKeyFrame(
			{
				glm::rotate(m_LocalTransform, glm::radians(45.0f), glm::vec3(0, 1, 0)),
				1
			}
		);

		m_Animation->AddKeyFrame(
			{
				glm::rotate(m_LocalTransform, glm::radians(-45.0f), glm::vec3(0, 1, 0)),
				1
			}
		);		
	}
};