
#version 330 core

layout(location = 0) in vec3 vertex;


uniform mat4 model_view_matrix;
uniform mat4 projection_matrix;

out vec3 frontColor;

void main()
{
	vec4 position = model_view_matrix * vec4(vertex, 1.0);

	vec3 fogColor = vec3(0.2, 0.2, 0.2);
	float fogNear = 1;
	float fogFar = 15;

	float fogIntensity = 1.0 - clamp((fogFar + position.z) / (fogFar - fogNear), 0.0, 1.0);

	gl_Position = projection_matrix * position;
	frontColor = mix(vec3(1.0, 1.0, 1.0), fogColor, fogIntensity);
}







