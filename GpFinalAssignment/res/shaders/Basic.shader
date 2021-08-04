#shader vertex
#version 460 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

out vec2 TexCoord;

void main()
{
	gl_Position = position;
	TexCoord = texCoord;
};

#shader fragment
#version 460 core

out vec4 FragColor;

layout(location = 0) out vec4 color;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
	FragColor = texture(ourTexture, TexCoord);
	//color = vec4(1.0, 0.0, 0.0, 1.0);
};