#include "PrimitiveMeshes.h"

std::vector<glm::vec2> PrimitiveMeshes::GetCirclePositions(const float sides)
{
	std::vector<glm::vec2> positions;

	float step = 2 * M_PI / sides;

	for (int i = 0; i <= sides; i++) 
	{
		positions.push_back(glm::vec2(cos(i * step), sin(i * step)));
	}

	return positions;
}

PrimitiveMesh PrimitiveMeshes::Circle(const float x, const float y, const float z, const float radius, const unsigned int sides)
{
	std::vector<glm::vec2> circlePositions = GetCirclePositions(sides);

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;

	vertices.push_back(glm::vec3(x, y, z));
	normals.push_back(glm::vec3(0, 1, 0));
	uvs.push_back(glm::vec2(.5, .5));

	for (int i = 1; i <= sides + 1; i++)
	{
		float xVal = (radius * circlePositions[i - 1].x);
		float yVal = (radius * circlePositions[i - 1].y);

		vertices.push_back(glm::vec3(
			x + xVal,
			y + yVal,
			z
		));

		normals.push_back(glm::vec3(0, 0, -1));

		uvs.push_back(
			glm::vec2(
				xVal / radius * .5 + .5,
				yVal / radius * .5 + .5
			)
		);
	}

	return { vertices, normals, uvs };
}

PrimitiveMesh PrimitiveMeshes::Cylinder(const float x, const float y, const float z, const float radius, const unsigned int sides)
{
	std::vector<glm::vec2> circlePositions = GetCirclePositions(sides);

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;

	for (int j = 0; j <= sides; j++)
	{
		float xr = circlePositions[j].x * radius;
		float yr = circlePositions[j].y * radius;

		vertices.push_back(glm::vec3(xr, yr, z / 2));
		vertices.push_back(glm::vec3(xr, yr, -z / 2));

		uvs.push_back(
			glm::vec2(
				(xr) / radius * .5 + .5,
				1
			)
		);

		uvs.push_back(
			glm::vec2(
				0,
				(yr) / radius * .5 + .5
			)
		);
	}

	for (auto vertex : vertices)
	{
		normals.push_back(vertex);
	}

	return { vertices, normals, uvs };
}

PrimitiveMesh PrimitiveMeshes::Cube(const float width, const float length, const float height)
{
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;

	vertices = {
		glm::vec3(-1.0f,-1.0f,-1.0f),
		glm::vec3(-1.0f,-1.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, 1.0f,-1.0f),
		glm::vec3(-1.0f,-1.0f,-1.0f),
		glm::vec3(-1.0f, 1.0f,-1.0f),

		glm::vec3(1.0f,-1.0f, 1.0f),
		glm::vec3(-1.0f,-1.0f,-1.0f),
		glm::vec3(1.0f,-1.0f,-1.0f),
		glm::vec3(1.0f, 1.0f,-1.0f),
		glm::vec3(1.0f,-1.0f,-1.0f),
		glm::vec3(-1.0f,-1.0f,-1.0f),

		glm::vec3(-1.0f,-1.0f,-1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f,-1.0f),
		glm::vec3(1.0f,-1.0f, 1.0f),
		glm::vec3(-1.0f,-1.0f, 1.0f),
		glm::vec3(-1.0f,-1.0f,-1.0f),

		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f,-1.0f, 1.0f),
		glm::vec3(1.0f,-1.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f,-1.0f,-1.0f),
		glm::vec3(1.0f, 1.0f,-1.0f),

		glm::vec3(1.0f,-1.0f,-1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f,-1.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, 1.0f,-1.0f),
		glm::vec3(-1.0f, 1.0f,-1.0f),

		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f,-1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f,-1.0f, 1.0f),
	};

	normals = 
	{
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),

		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),

		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),

		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),

		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),

		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0)
	};

	uvs =
	{
		glm::vec2(1, 1),
		glm::vec2(1, 0),
		glm::vec2(0, 0),

		glm::vec2(1, 1),
		glm::vec2(0, 0),
		glm::vec2(1, 0),

		glm::vec2(1, 1),
		glm::vec2(0, 0),
		glm::vec2(0, 1),

		glm::vec2(1, 1),
		glm::vec2(0, 1),
		glm::vec2(0, 0),

		glm::vec2(1, 1),
		glm::vec2(0, 0),
		glm::vec2(0, 1),

		glm::vec2(1, 1),
		glm::vec2(1, 0),
		glm::vec2(0, 0),

		glm::vec2(1, 1),
		glm::vec2(0, 1),
		glm::vec2(0, 0),

		glm::vec2(1, 1),
		glm::vec2(0, 0),
		glm::vec2(0, 1),

		glm::vec2(0, 0),
		glm::vec2(1, 1),
		glm::vec2(1, 0),

		glm::vec2(1, 1),
		glm::vec2(1, 0),
		glm::vec2(0, 0),

		glm::vec2(1, 1),
		glm::vec2(0, 0),
		glm::vec2(0, 1),

		glm::vec2(1, 1),
		glm::vec2(1, 0),
		glm::vec2(0, 0),
	};

	return { vertices, normals, uvs };
}