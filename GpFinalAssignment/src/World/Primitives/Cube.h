#include "../Object.h"

#include <glad/glad.h>
#include <math.h>

#include "../Renderer/Material.h"
#include "../Helpers/PrimitiveMeshes.h"

class Cube : public Object
{
public:
	Cube(glm::vec3 translation = glm::vec3(0, 0, 0)) : Object(
		new Mesh(
			PrimitiveMeshes::Cube(0, 0, 0)
		),
		new Shader("assets/shaders/vertex.shader", "assets/shaders/fragment.shader"),
		new Material())
	{
		Texture* diffuse = new Texture(DIFFUSE, "assets/models/cube/wood_cube.bmp", "diffuseMap", *m_Shader);

		m_Material->AddTexture(diffuse);

		m_LocalTransform = glm::translate(m_LocalTransform, translation);
	}
};