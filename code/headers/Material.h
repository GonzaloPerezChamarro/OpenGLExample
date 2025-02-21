/**
 * @file Material.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase material que reune ushader y texturas, asi como color
 * @brief Class that represents a material, that groups shader, textures and color
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef MATERIAL_HEADER
#define MATERIAL_HEADER

#include "Texture2D.h"
#include "ShaderProgram.h"
#include "Variant.h"
#include <map>
#include <string>

namespace example
{
	class Material
	{
	private:
		/* Pointer to main shader */
		std::shared_ptr < Shader_Program> shader;
		
		/* Material id */
		std::string id;

		/* Mpa of uniform variables */
		std::map<std::string, Variant> variables;

		/* Main texture */
		std::shared_ptr<Texture> texture;

		/* Albedo color */
		glm::vec3 color;

	public:
		/* Map of materials. Factory */
		static std::map<std::string, std::shared_ptr<Material>> factory;

		/**
		 * @brief Returns the material if is already created. Otherwise, it creates a new one
		 * @param shader_name Name of the shader
		 * @param vertex_path Path to the shader
		 * @param fragment_path Path to the fragment shader
		 * @param color Albedo
		 * @param texture_path Path to the texture
		 * @param variants Uniform variables
		 * @return std::shared_ptr<Material> Created material
		 */
		static std::shared_ptr<Material> get(const std::string & shader_name,
										const std::string & vertex_path,
										const std::string & fragment_path,
										const glm::vec3 & color = { 1,1,1 },
										const std::string & texture_path = "../../assets/textures/default.tga",
										const std::map<std::string, Variant> & variants = std::map<std::string, Variant>());

	public:

		/* Constructor by a shader program */
		Material(const std::shared_ptr<Shader_Program>& shader_program)
			:shader(shader_program)
		{}

		/* Constructor */
		Material(const std::string & shader_name,
				const std::string & vertex_path,
				const std::string & fragment_path,
				const std::string & texture_path,
				const std::map<std::string, Variant> & variants
		);

	public:
		/* Indicates to OpenGL that this material is going to be used */
		void use();

		/* Returns the shader */
		std::shared_ptr<Shader_Program> get_shader() const { return shader; }

		/* Returns the main texture */
		std::shared_ptr<Texture> get_texture() const { return texture; }

		/* Returns the material id */
		std::string get_id() const { return id; }

		/* Returns the color*/
		glm::vec3 get_color() const { return color; }

		/* Modifies the color */
		void set_color(glm::vec3 c) { color = c; }

		/* Method to add a uniform variable */
		bool add_variant(const std::string & name, const GLint value);
		bool add_variant(const std::string & name, const GLuint value);
		bool add_variant(const std::string & name, const GLfloat value);
		bool add_variant(const std::string & name, const glm::vec2 value);
		bool add_variant(const std::string & name, const glm::vec3 value);
		bool add_variant(const std::string & name, const glm::vec4 value);

		/* Method to modify a variable */
		void set_value(const std::string & variant_name, Variant value);
	};
}

#endif
