#include "Material.h"

#include <glad/glad.h>


Material::Material(glm::vec3 lightPosition, glm::vec3 materialAmbientColor, glm::vec3 materialDiffuseColor, glm::vec3 materialSpecularColor, int materialRoughness)
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
	shader->SetUniform3fv("lightPosition", m_LightPosition);
	shader->SetUniform3fv("materialAmbientColor", m_MaterialAmbientColor);
	shader->SetUniform3fv("materialDiffuseColor", m_MaterialDiffuseColor);
	shader->SetUniform3fv("materialSpecularColor", m_MaterialSpecularColor);
	shader->SetUniform1f("materialRoughness", m_MaterialRoughness);
}
