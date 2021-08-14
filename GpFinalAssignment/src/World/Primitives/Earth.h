#include "../Object.h"

#include <glad/glad.h>
#include <math.h>

#include "../Renderer/Material.h"
#include "PrimitiveMeshes.h"

struct CirclePrimitive
{
	std::vector<glm::vec3> m_Vertices;
	std::vector<glm::vec3> m_Normals;
	std::vector<glm::vec2> m_Uvs;
};

class Earth : public Object
{
public:
	Earth(glm::vec3 translation = glm::vec3(0, 0, 0)) : Object(
		new Mesh(
			PrimitiveMeshes::Circle(0, 0, 0, 1, 20),
			GL_TRIANGLE_FAN
		),
		new Shader("assets/shaders/vertex.shader", "assets/shaders/fragment.shader"),
		new Material(),
		new Animation())
	{
		Texture* diffuse = new Texture(DIFFUSE, "assets/models/earth/earth.bmp", "diffuseMap", *m_Shader);

		m_Material->AddTexture(diffuse);

		m_LocalTransform = glm::translate(m_LocalTransform, translation);

		m_Animation->SetLocalTransform(m_LocalTransform);

		// Orbiting earth animation.
		m_Animation->AddKeyFrame(
			{
				glm::translate(m_LocalTransform, glm::vec3(0, 0, 0)),
				1
			}
		);

		m_Animation->AddKeyFrame(
			{
				glm::translate(m_LocalTransform, glm::vec3(-7, 2, 0)),
				1
			}
		);

		m_Animation->AddKeyFrame(
			{
				glm::translate(m_LocalTransform, glm::vec3(-14, 0, 0)),
				1
			}
		);

		m_Animation->AddKeyFrame(
			{
				glm::translate(m_LocalTransform, glm::vec3(-7, 2, 0)),
				1
			}
		);

		m_Animation->AddKeyFrame(
			{
				glm::translate(m_LocalTransform, glm::vec3(0, 0, 0)),
				1
			}
		);
	}
};