#include "../Object.h"

#include "PrimitiveMeshes.h"

class MetalTube : public Object
{
public:
	MetalTube(glm::vec3 translation = glm::vec3(0, 0, 0), glm::vec3 rotation = glm::vec3(0, 0, 0)) : Object(
		new Mesh(
			PrimitiveMeshes::Cylinder(0, 0, 3, .2, 20),
			GL_QUAD_STRIP
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
		Texture* diffuse = new Texture(DIFFUSE, "assets/models/metal_tube/metal_tube.bmp", "diffuseMap", *m_Shader);

		m_Material->AddTexture(diffuse);

		m_LocalTransform = glm::rotate(m_LocalTransform, glm::radians(rotation.x), glm::vec3(1, 0, 0));
		m_LocalTransform = glm::rotate(m_LocalTransform, glm::radians(rotation.y), glm::vec3(0, 1, 0));
		m_LocalTransform = glm::rotate(m_LocalTransform, glm::radians(rotation.z), glm::vec3(0, 0, 1));

		m_LocalTransform = glm::translate(m_LocalTransform, translation);
	}
};