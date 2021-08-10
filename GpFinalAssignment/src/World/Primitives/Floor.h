#include "../Object.h"
#include "../Renderer/Material.h"

class Floor : public Object
{
public:
	Floor(glm::vec3 translation = glm::vec3(0, 0, 0)) : Object(
		new Mesh(
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
		),
		new Shader(""),
		new Material("assets/models/floor/floor.bmp"))
	{
		// Scale the floor on x and y axis to match the width of the scene.
		m_Transform = glm::scale(m_Transform, glm::vec3(30, 0.01f, 30));
		m_Transform = glm::translate(m_Transform, translation);
	}
};