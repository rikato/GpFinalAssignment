#include "Material.h"

#include <glad/glad.h>


Material::Material(glm::vec3 lightPosition, glm::vec3 materialAmbientColor, glm::vec3 materialDiffuseColor, glm::vec3 materialSpecularColor, float materialRoughness)
	:m_LightPosition(lightPosition), m_MaterialAmbientColor(materialAmbientColor), m_MaterialDiffuseColor(materialDiffuseColor), m_MaterialSpecularColor(materialSpecularColor), m_MaterialRoughness(materialRoughness)
{
}

Material::~Material()
{
}

void Material::AddTexture(Texture* texture)
{
	m_Textures.push_back(texture);
}

void Material::BindUniforms(Shader* shader)
{
	shader->SetUniform<glm::vec3>("lightPosition", m_LightPosition);
	shader->SetUniform<glm::vec3>("materialAmbientColor", m_MaterialAmbientColor);
	shader->SetUniform<glm::vec3>("materialDiffuseColor", m_MaterialDiffuseColor);
	shader->SetUniform<glm::vec3>("materialSpecularColor", m_MaterialSpecularColor);
	shader->SetUniform<float>("materialRoughness", m_MaterialRoughness);
}
