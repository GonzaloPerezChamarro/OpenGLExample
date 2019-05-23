

#include "Material.hpp"
#include <glm.hpp>


namespace example
{
	std::map<std::string, std::shared_ptr<Material>> Material::factory;


	std::shared_ptr<Material> Material::get(const std::string & shader_name, const std::string & vertex_path, const std::string & fragment_path, const glm::vec3 & c, const std::string & texture_path, const std::map<std::string, Variant>& variants )
	{
		std::string id_temp = (vertex_path + fragment_path + texture_path);

		if (factory.count(id_temp) > 0 && factory[id_temp]->get_color() == c )
		{
			return factory[id_temp];
		}

		std::shared_ptr<Material> material(new Material(shader_name, vertex_path, fragment_path, texture_path, variants));
		material->set_color(c);

		if (!material->get_shader()->is_usable())
			material.reset();
		else
			factory[id_temp] = material;

		return material;
	}

	Material::Material(const std::string & shader_name, const std::string & vertex_path, const std::string & fragment_path, const std::string & texture_path , const std::map<std::string, Variant>& variants)
		:texture(nullptr)
	{
		id = vertex_path + fragment_path + texture_path;

		texture = Texture2D::get_texture(texture_path);

		//shader
		shader = Shader_Program::create_shader(shader_name, vertex_path, fragment_path);

		for (auto & value : variants)
		{
			set_value(value.first, value.second);
		}
	}

	void Material::use()
	{
		shader->use();

		for (auto & variant : variables)
		{
			switch (variant.second.type)
			{
			case Variant::Type::INT:
				shader->set_variant_value(variant.second.id, variant.second.value.integer);
				break;
			case Variant::Type::FLOAT:
				shader->set_variant_value(variant.second.id, variant.second.value.f);
				break;
			case Variant::Type::VEC2:
				shader->set_variant_value(variant.second.id, glm::vec2(variant.second.value.vec2[0], variant.second.value.vec2[1]));
				break;
			case Variant::Type::VEC3:
				shader->set_variant_value(variant.second.id, glm::vec3(variant.second.value.vec3[0], variant.second.value.vec3[1], variant.second.value.vec3[2]));
				break;
			case Variant::Type::VEC4:
				shader->set_variant_value(variant.second.id, glm::vec4(variant.second.value.vec4[0], variant.second.value.vec4[1], variant.second.value.vec4[2], variant.second.value.vec4[3]));
				break;
			default:
				break;
			}
		}
	}

	bool Material::add_variant(const std::string & name, const GLint value)
	{
		GLuint location = shader->get_uniform_location(name.c_str());
		Variant variant;

		if (location < 0) return false;

		variant.id = location;
		variant.type = Variant::Type::INT;
		variant.value.integer = value;

		variables[name] = variant;

		return true;
	}

	bool Material::add_variant(const std::string & name, const GLuint value)
	{
		GLuint location = shader->get_uniform_location(name.c_str());
		Variant variant;

		if (location < 0) return false;

		variant.id = location;
		variant.type = Variant::Type::UINT;
		variant.value.uinteger = value;

		variables[name] = variant; 

		return true;
	}

	bool Material::add_variant(const std::string & name, const GLfloat value)
	{
		GLuint location = shader->get_uniform_location(name.c_str());
		Variant variant;

		if (location < 0) return false;

		variant.id = location;
		variant.type = Variant::Type::FLOAT;
		variant.value.f = value;

		variables[name] = variant;

		return true;
	}

	bool Material::add_variant(const std::string & name, const glm::vec2 value)
	{
		GLuint location = shader->get_uniform_location(name.c_str());
		Variant variant;

		if (location < 0) return false;

		variant.id = location;
		variant.type = Variant::Type::VEC2;
		variant.value.vec2[0] = value[0];
		variant.value.vec2[1] = value[2];

		variables[name] = variant; 

		return true;
	}

	bool Material::add_variant(const std::string & name, const glm::vec3 value)
	{
		GLuint location = shader->get_uniform_location(name.c_str());
		Variant variant;

		if (location < 0) return false;

		variant.id = location;
		variant.type = Variant::Type::VEC3;
		variant.value.vec3[0] = value[0];
		variant.value.vec3[1] = value[1];
		variant.value.vec3[2] = value[2];

		variables[name] = variant;

		return true;
	}

	bool Material::add_variant(const std::string & name, const glm::vec4 value)
	{
		GLuint location = shader->get_uniform_location(name.c_str());
		Variant variant;

		if (location < 0) return false;

		variant.id = location;
		variant.type = Variant::Type::VEC4;
		variant.value.vec4[0] = value[0];
		variant.value.vec4[1] = value[1];
		variant.value.vec4[2] = value[2];
		variant.value.vec4[3] = value[3];

		variables[name] = variant;

		return true;
	}

	void Material::set_value(const std::string & variant_name, Variant value)
	{
		if (variables.count(variant_name) > 0) variables[variant_name] = value;
	}
}