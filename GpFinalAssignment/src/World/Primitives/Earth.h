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

	inline const CirclePrimitive Cylinder(const float x, const float y, const float z, const float radius, const unsigned int sides)
	{	
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;

		float sectorStep = 2 * M_PI / sides;
		float sectorAngle;

		std::vector<glm::vec2> unitCircleVertices;
		for (int i = 0; i <= sides; ++i)
		{
			sectorAngle = i * sectorStep;
			unitCircleVertices.push_back(glm::vec3(cos(sectorAngle), sin(sectorAngle), 0));
		}



		for (int j = 0; j <= sides; j++)
		{
			vertices.push_back(glm::vec3(unitCircleVertices[j].x * radius, unitCircleVertices[j].y * radius, z/2));
			vertices.push_back(glm::vec3(unitCircleVertices[j].x * radius, unitCircleVertices[j].y * radius, -z/2));

			uvs.push_back(
				glm::vec2(
					(unitCircleVertices[j].x * radius) / radius * .5 + .5,
					(unitCircleVertices[j].y * radius) / radius * .5 + .5
				)
			);

			uvs.push_back(
				glm::vec2(
					
					(unitCircleVertices[j].y * radius) / radius * .5 + .5,
					(unitCircleVertices[j].x * radius) / radius * .5 + .5
				)
			);
		}
		


		//for (int i = 0; i < 2; i++) 
		//{
		//	// First iteration is -half the height second is half the height for z.
		//	float h = i == 0 ? (height / 2 + x) : (-height / 2 + -x);


		//	vertices.push_back(glm::vec3(x, y, h));
		//	normals.push_back(glm::vec3(0, 1, 0));
		//	uvs.push_back(glm::vec2(.5, .5));

		//	for (int j = 1; j < sides + 2; j++)
		//	{
		//		float xVal = (radius * cos(j * M_PI * 2 / sides));
		//		float yVal = (radius * sin(j * M_PI * 2 / sides));

		//		vertices.push_back(glm::vec3(
		//			x + xVal,
		//			y + yVal,
		//			h
		//		));

		//		uvs.push_back(
		//			glm::vec2(
		//				xVal / radius * .5 + .5,
		//				yVal / radius * .5 + .5
		//			)
		//		);
		//	}
		//}


		for (auto vertex : vertices) 
		{
			//uvs.push_back(
			//	glm::vec2(
			//		vertex.x / radius * .5 + .5,
			//		vertex.y / radius * .5 + .5
			//	)
			//);

			normals.push_back(vertex);
		}

		return { vertices, normals, uvs };
	};

	Earth(glm::vec3 translation = glm::vec3(0, 0, 0)) : Object(
		new Mesh(
			// Vertices.
			Cylinder(0, 0, 4, 2, 6).m_Vertices,
			// Normals.
			Cylinder(0, 0, 4, 2, 6).m_Normals,
			// Uvs.
			Cylinder(0, 0, 4, 2, 6).m_Uvs,
			GL_QUAD_STRIP
			),
		new Shader("assets/shaders/vertex.shader", "assets/shaders/fragment.shader"),
		new Material())
	{
		Texture* diffuse = new Texture(DIFFUSE, "assets/models/earth/earth.bmp", "diffuseMap", *m_Shader);

		m_Material->AddTexture(diffuse);

		m_LocalTransform = glm::translate(m_LocalTransform, translation);
	}
};