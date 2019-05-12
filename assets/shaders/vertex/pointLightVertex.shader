
#version 330 core

layout(location = 0) in vec3 vertex;
layout(location = 1) in vec3 colors;
layout(location = 2) in vec3 texCoords;
layout(location = 3) in vec3 normals;


uniform mat4 modelViewMatrix;

uniform mat4 projectionMatrix;

out vec2 TexCoords;
out vec4 ModelPosition;
out vec4 Normal;

void main()
{
	vec4 modelPosition = modelViewMatrix * vec4(vertex, 1.0);
	ModelPosition = modelPosition;

	vec4 normal = transpose(inverse(modelViewMatrix)) * vec4(normals, 1.0);
	Normal = normal;

	TexCoords = texCoords.xy;
	
	gl_Position = projectionMatrix * modelPosition;
}







