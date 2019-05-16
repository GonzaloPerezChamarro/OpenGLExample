

#ifndef MATERIAL_HEADER
#define MATERIAL_HEADER

#include "Texture2D.hpp"
#include "ShaderProgram.hpp"
#include "Variant.hpp"
#include <map>
#include <string>

namespace example
{
	class Material
	{
	private:
		std::shared_ptr < Shader_Program> shader;
		
		std::string id;
		std::map<std::string, Variant> variables;

		std::shared_ptr<Texture> texture;
		glm::vec3 color;

	public:
		static std::map<std::string, std::shared_ptr<Material>> factory;

		static std::shared_ptr<Material> get(const std::string & shader_name,
										const std::string & vertex_path,
										const std::string & fragment_path,
										const glm::vec3 & color = { 1,1,1 },
										const std::string & texture_path = "../../assets/textures/default.tga",
										const std::map<std::string, Variant> & variants = std::map<std::string, Variant>());

	public:

		Material(const std::shared_ptr<Shader_Program>& shader_program)
			:shader(shader_program)
		{}

		Material(const std::string & shader_name,
				const std::string & vertex_path,
				const std::string & fragment_path,
				const std::string & texture_path,
				const std::map<std::string, Variant> & variants
		);

	public:

		void use();

		std::shared_ptr<Shader_Program> get_shader() const { return shader; }

		std::string get_id()const { return id; }

		bool add_variant(const std::string & name, const GLint value);
		bool add_variant(const std::string & name, const GLuint value);
		bool add_variant(const std::string & name, const GLfloat value);
		bool add_variant(const std::string & name, const glm::vec2 value);
		bool add_variant(const std::string & name, const glm::vec3 value);
		bool add_variant(const std::string & name, const glm::vec4 value);

		void set_value(const std::string & variant_name, Variant value);

		std::shared_ptr<Texture> get_texture() { return texture; }

		glm::vec3 get_color() const { return color; }
		void set_color(glm::vec3 c) { color = c; }


	};
}


#endif
