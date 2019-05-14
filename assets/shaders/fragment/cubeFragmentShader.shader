
#version 330 core

uniform vec3 _Color;
uniform vec3 lightColor;

in vec3 frontColor;
out vec4 FragColor;

void main()
{
	FragColor = vec4(frontColor * _Color, 1.0);
}