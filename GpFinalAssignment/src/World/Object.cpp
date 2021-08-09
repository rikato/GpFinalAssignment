#include "Object.h"

Object::Object(Mesh* mesh, Shader* shader)
	:mesh(nullptr), shader(nullptr), transform(glm::translate(glm::mat4(1.0), glm::vec3(0, 0, 0)))
{
	this->mesh = mesh;
	this->shader = shader;

	this->shader->Bind();
}

Object::~Object()
{
	delete this->mesh;
	delete this->shader;
}

void Object::Update(glm::mat4 mvMatrix, glm::mat4 projectionMatrix)
{
	this->shader->updateMv(mvMatrix * this->transform);
	this->shader->updateProjection(projectionMatrix);

	this->mesh->Draw();
}
