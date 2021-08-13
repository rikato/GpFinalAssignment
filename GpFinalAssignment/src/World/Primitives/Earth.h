#include "../Object.h"

#include <glad/glad.h>
#include <math.h>
#include "../Renderer/Material.h"

#define M_PI 3.14159265358979323846

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
		normals.push_back(glm::vec3(0, 1, 0));
		uvs.push_back(glm::vec2(.5, .5));

		for (int i = 1; i < sides + 2; i++)
		{
			float xVal = (radius * cos(i * M_PI * 2 / sides));
			float yVal = (radius * sin(i * M_PI * 2 / sides));

			vertices.push_back(glm::vec3(
				x + xVal,
				y + yVal,
				z
			));

			normals.push_back(glm::vec3(0, 0, -1));

			uvs.push_back(
				glm::vec2(
					xVal / radius *.5 + .5,
					yVal / radius * .5 + .5
				)
			);
		}

		return { vertices, normals, uvs };
	};

	Earth(glm::vec3 translation = glm::vec3(0, 0, 0)) : Object(
		new Mesh(
			// Vertices.
			Circle(0, 0, 0, 1, 20).m_Vertices,
			// Normals.
			Circle(0, 0, 0, 1, 20).m_Normals,
			// Uvs.
			Circle(0, 0, 0, 1, 20).m_Uvs,
			GL_TRIANGLE_FAN
			),
		new Shader("assets/shaders/vertex.shader", "assets/shaders/fragment.shader"),
		new Material())
	{
		Texture* diffuse = new Texture(DIFFUSE, "assets/models/earth/earth.bmp", "diffuseMap", *m_Shader);

		m_Material->AddTexture(diffuse);

		m_LocalTransform = glm::translate(m_LocalTransform, translation);
	}
};