#shader vertex
#version 460 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

out vec2 TexCoord;

uniform mat4 MVP;

void main()
{
	gl_Position = MVP * position;
	TexCoord = texCoord; 
};

#shader fragment
#version 460 core

out vec4 FragColor;

layout(location = 0) out vec4 color;
in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform vec4 u_Color;

void main()
{
	//FragColor = texture(ourTexture, TexCoord);
	color = u_Color;
};