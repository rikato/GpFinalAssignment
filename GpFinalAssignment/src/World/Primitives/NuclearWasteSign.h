#include "../Object.h"

#include "PrimitiveMeshes.h"

class NuclearWasteSign : public Object
{
public:
	NuclearWasteSign(glm::vec3 translation = glm::vec3(0, 0, 0), glm::vec3 rotation = glm::vec3(0, 0, 0)) : Object(
		new Mesh(
			PrimitiveMeshes::Circle(0, 0, 0, .6, 6),
			GL_TRIANGLE_FAN
		),
		new Shader("assets/shaders/vertex.shader", "assets/shaders/fragment.shader"),
		new Material(
			glm::vec3(0.0, 4.0, 4.0),
			glm::vec3(0.0, 0.0, 0.1),
			glm::vec3(1.3, 1.3, 1.3),
			glm::vec3(1, 1, 1),
			1024
		))
	{
		Texture* diffuse = new Texture(DIFFUSE, "assets/models/nuclear_waste_sign/nuclear_waste_sign.bmp", "diffuseMap", *m_Shader);

		m_Material->AddTexture(diffuse);

		m_LocalTransform = glm::rotate(m_LocalTransform, glm::radians(rotation.x), glm::vec3(1, 0, 0));
		m_LocalTransform = glm::rotate(m_LocalTransform, glm::radians(rotation.y), glm::vec3(0, 1, 0));
		m_LocalTransform = glm::rotate(m_LocalTransform, glm::radians(rotation.z), glm::vec3(0, 0, 1));

		m_LocalTransform = glm::translate(m_LocalTransform, translation);
	}
};