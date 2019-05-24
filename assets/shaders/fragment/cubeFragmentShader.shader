
#version 330 core

uniform vec3 _Color;
uniform vec3 lightColor;
uniform sampler2D _MainTex;

in vec3 frontColor;
in vec2 TexCoords;

out vec4 FragColor;

void main()
{
	vec3 result = frontColor * _Color;
	FragColor = vec4(result * texture(_MainTex, TexCoords.st).rgb, 1.0);
	
}