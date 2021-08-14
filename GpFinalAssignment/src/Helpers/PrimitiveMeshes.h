#pragma once
#include <vector>
#include <math.h>
#include <glad/glad.h>

#include "glm/glm.hpp"

#define M_PI 3.14159265358979323846

struct PrimitiveMesh
{
	std::vector<glm::vec3> m_Vertices;
	std::vector<glm::vec3> m_Normals;
	std::vector<glm::vec2> m_Uvs;
};


class PrimitiveMeshes 
{
private:
	static std::vector<glm::vec2> GetCirclePositions(const float sides);
public:
	static PrimitiveMesh Circle(const float x, const float y, const float z, const float radius, const unsigned int sides);
	static PrimitiveMesh Cylinder(const float x, const float y, const float z, const float radius, const unsigned int sides);
};