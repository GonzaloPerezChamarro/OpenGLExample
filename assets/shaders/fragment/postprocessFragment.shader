
#version 330 core

uniform sampler2D sampler2d;

in vec2 texture_uv;
out vec4 fragment_color;

void main()
{
	vec3 color = texture(sampler2d, texture_uv.st).rgb;
	float i = (color.r + color.g + color.b) * 0.3333;
	fragment_color = vec4(vec3(i, i, i) * vec3(1.0, 0.75, 0.5), 1.0);
}








