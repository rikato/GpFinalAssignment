#pragma once
#include <string>
#include <vector>
#include <map>

#include "../Renderer/Shader.h"
#include "../Renderer/Texture.h"

class Material 
{
private:
	glm::vec3 m_LightPosition;
	glm::vec3 m_MaterialAmbientColor;
	glm::vec3 m_MaterialDiffuseColor;
	glm::vec3 m_MaterialSpecularColor;
	int m_MaterialRoughness;

public:
	Material(glm::vec3 lightPosition, glm::vec3 materialAmbientColor, glm::vec3 materialDiffuseColor, glm::vec3 materialSpecularColor, float materialRoughness);
	~Material();

	std::vector<Texture*> m_Textures;

	void AddTexture(Texture* texture);
	void BindUniforms(Shader* shader);
};
