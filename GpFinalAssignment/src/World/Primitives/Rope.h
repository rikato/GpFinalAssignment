#include "../Object.h"

#include <glad/glad.h>
#include <math.h>

#include "../Renderer/Material.h"
#include "../Helpers/PrimitiveMeshes.h"

class Rope : public Object
{
public:
	Rope(glm::vec3 translation = glm::vec3(0, 0, 0), glm::vec3 rotation = glm::vec3(0, 0, 0)) : Object(
		new Mesh(
			PrimitiveMeshes::Cylinder(0, 0, 5, .05, 10),
			GL_QUAD_STRIP
		),
		new Shader("assets/shaders/vertex.shader", "assets/shaders/fragment.shader"),
		new Material())
	{
		Texture* diffuse = new Texture(DIFFUSE, "assets/models/rope/rope.bmp", "diffuseMap", *m_Shader);

		m_Material->AddTexture(diffuse);

		m_LocalTransform = glm::translate(m_LocalTransform, translation);

		m_LocalTransform = glm::rotate(m_LocalTransform, glm::radians(rotation.x), glm::vec3(1, 0, 0));
		m_LocalTransform = glm::rotate(m_LocalTransform, glm::radians(rotation.y), glm::vec3(0, 1, 0));
		m_LocalTransform = glm::rotate(m_LocalTransform, glm::radians(rotation.z), glm::vec3(0, 0, 1));
	}
};