
#version 330 core

layout(location = 0) in vec3 vertex;
layout(location = 1) in vec3 colors;
layout(location = 2) in vec3 texCoords;
layout(location = 3) in vec3 normals;

uniform mat4 projection_matrix;
uniform mat4 model_view_matrix;

out vec3 frontColor;
out vec2 TexCoords;


void main()
{
	vec4 position = model_view_matrix * vec4(vertex, 1.0);

	vec3 fogColor = vec3(0.2, 0.2, 0.2);
	float fogNear = 1;
	float fogFar = 100;

	float fogIntensity = 1.0 - clamp((fogFar + position.z) / (fogFar - fogNear), 0.0, 1.0);
		
	gl_Position = projection_matrix * position;
	frontColor = mix(vec3(1.0, 1.0, 1.0), fogColor, fogIntensity);

	TexCoords = texCoords.xy;
}