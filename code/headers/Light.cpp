#include "Light.h"
#include "ShaderProgram.h"

void example::Light::render(Camera & camera)
{
	//Ajuste de variables uniformes del shader default
	auto light_shader = Shader_Program::get_shader("lightShader");
	light_shader->use();
	transform = glm::mat4();
	transform = camera.get_view();
	transform.translate(position);
	light_shader->set_variant_value("light.position", transform.get_position());
	light_shader->set_variant_value("light.color", glm::vec3(1.0f, 1.0f, 1.0f));
	light_shader->set_variant_value("ambientIntensity", get_ambient_intensity());
	light_shader->set_variant_value("intensity", get_intensity());
	light_shader->set_variant_value("viewPosition", camera.get_position());

	light_shader->set_variant_value("_Color", glm::vec3(1.0f, 1.0f, 1.0f));
}
