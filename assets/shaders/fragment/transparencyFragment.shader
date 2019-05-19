
#version 330 core



in vec3 frontColor;
out vec4 FragColor;


uniform vec3 _Color;
uniform sampler2D _MainTex;

void main()
{
	FragColor = vec4(frontColor * _Color, 0.8);
}








