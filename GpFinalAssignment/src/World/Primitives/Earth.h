#include "../Object.h"

#include <glad/glad.h>
#include <math.h>
#include "../Renderer/Material.h"

# define M_PI 3.14159265358979323846

struct CirclePrimitive 
{
	std::vector<glm::vec3> m_Vertices;
	std::vector<glm::vec3> m_Normals;
	std::vector<glm::vec2> m_Uvs;
};

class Earth : public Object
{
public:
	inline const CirclePrimitive Circle(const float x, const float y, const float z, const float radius, const unsigned int sides)
	{
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;

		vertices.push_back(glm::vec3(x, y, z));

		for (int i = 1; i < sides + 2; i++)
		{
			float xVal = x + radius * cos(i * M_PI * 2 / sides);
			float yVal = y + radius * sin(i * M_PI * 2 / sides);

			vertices.push_back(glm::vec3(
				xVal,
				yVal,
				z
			));

			normals.push_back(glm::vec3(0, 1, 0));

			uvs.push_back(glm::vec2(xVal * 0.5 + 0.5, yVal * 0.5 + 0.5));
		}

		return {vertices, normals, uvs};
	};

	Earth(glm::vec3 translation = glm::vec3(0, 0, 0)) : Object(
		new Mesh(
			// Vertices.
			Circle(2, 2, 2, 2, 6).m_Vertices,
			// Normals.
			Circle(2, 2, 0, 2, 6).m_Normals,
			// Uvs.
			{ 
				glm::vec2(0, 0),
				glm::vec2(1, 0),
				glm::vec2(1, 1),
				glm::vec2(0, 1),

			},
			GL_TRIANGLE_FAN
		),
		new Shader(""),
		new Material("assets/models/floor/floor.bmp"))
	{
		// Scale the floor on x and y axis to match the width of the scene.
		m_Transform = glm::translate(m_Transform, translation);

		auto x = m_Mesh;
	}
};