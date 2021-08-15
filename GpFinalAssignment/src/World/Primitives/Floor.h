#include "../Object.h"
#include "../Renderer/Material.h"

class Floor : public Object
{
public:
	Floor(glm::vec3 translation = glm::vec3(0, 0, 0)) : Object(
		new Mesh(
			{
				// Vertices.
				{
					glm::vec3(0, 0, 0),
					glm::vec3(0, 0, 1),
					glm::vec3(1, 0, 1),
					glm::vec3(1, 0, 1),
					glm::vec3(0, 0, 0),
					glm::vec3(1, 0, 0)
				},
				// Normals.
				{
					glm::vec3(0, 1, 0),
					glm::vec3(0, 1, 0),
					glm::vec3(0, 1, 0),
					glm::vec3(0, 1, 0),
					glm::vec3(0, 1, 0),
					glm::vec3(0, 1, 0)
				},
				// Uvs.
				// Tile the texture 10 * 10 times over the x and y axis.
				{
					glm::vec2(10, 10),
					glm::vec2(10, 0),
					glm::vec2(0, 0),
					glm::vec2(0, 0),
					glm::vec2(10, 10),
					glm::vec2(0, 10)
				} 
			}
		),
		new Shader("assets/shaders/vertex.shader", "assets/shaders/fragmentNormal.shader"),
		new Material(
			glm::vec3(0.0, 4.0, 4.0),
			glm::vec3(0.0, 0.0, 0.1),
			glm::vec3(1.3, 1.3, 1.3),
			glm::vec3(1, 1, 1),
			1024
		))
	{
		Texture* diffuse = new Texture(DIFFUSE, "assets/models/floor/floor.bmp", "diffuseMap", *m_Shader);
		Texture* normal = new Texture(NORMAL, "assets/models/floor/floor_normal.bmp", "normalMap", *m_Shader);

		m_Material->AddTexture(diffuse);
		m_Material->AddTexture(normal);

		// Scale the floor on x and y axis to match the width of the scene.
		m_LocalTransform = glm::scale(m_LocalTransform, glm::vec3(30, 0.01f, 30));
		m_LocalTransform = glm::translate(m_LocalTransform, translation);
	}
};