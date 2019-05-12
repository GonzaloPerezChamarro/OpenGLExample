
#version 330 core



// Luces
struct Light
{
	vec3 position;
	vec3 color;
};

uniform Light light;
uniform float ambientIntensity;
uniform float intensity;

uniform float specularIntensity;


uniform vec3 materialColor;

uniform vec3 viewPosition;


in vec2 TexCoords;
in vec4 ModelPosition;
in vec4 Normal;

out vec4 FragmentColor;

uniform sampler2D brickTexture;


void main()
{
	vec3 ambient = ambientIntensity * light.color;
	
	vec3 norm = Normal.xyz;
	vec3 lightDirection = light.position - ModelPosition.xyz;
	
	vec3 N = normalize(norm);
	vec3 L = normalize(lightDirection);
	
	vec3 diffuse = max(dot(N, L), 0.0) * intensity * light.color;
	
	vec3 V = normalize(viewPosition - ModelPosition.xyz);
	vec3 R = reflect(-L, N);
	
	vec3 specular = pow(max(dot(V, R), 0.0), 128) * light.color;	
	
	vec3 result = (ambient + diffuse + specular) * materialColor;

	FragmentColor = vec4(result * texture(brickTexture, TexCoords.st).rgb, 1.0);	
}








