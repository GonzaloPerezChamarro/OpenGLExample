/**
 * @file Material.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase material que reune ushader y texturas, asi como color
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

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
		/**
		 * @brief Shader principal
		 * 
		 */
		std::shared_ptr < Shader_Program> shader;
		
		/**
		 * @brief id del material
		 * 
		 */
		std::string id;

		/**
		 * @brief mapa de variables uniformes
		 * 
		 */
		std::map<std::string, Variant> variables;

		/**
		 * @brief Textura principal dell material
		 * 
		 */
		std::shared_ptr<Texture> texture;

		/**
		 * @brief Color del albedo
		 * 
		 */
		glm::vec3 color;

	public:
		/**
		 * @brief Mapa de materiales. Factoria
		 * 
		 */
		static std::map<std::string, std::shared_ptr<Material>> factory;

		/**
		 * @brief Devuelve el material si ya esta creado. EN caso contrario, crea uno nuevo
		 * 
		 * @param shader_name Nombre del shader
		 * @param vertex_path Ruta al vertex shader
		 * @param fragment_path Ruta al fragment shader
		 * @param color Color principal del albedo
		 * @param texture_path Ruta de textura
		 * @param variants Mapa de variables uniformes
		 * @return std::shared_ptr<Material> Puntero al material creado
		 */
		static std::shared_ptr<Material> get(const std::string & shader_name,
										const std::string & vertex_path,
										const std::string & fragment_path,
										const glm::vec3 & color = { 1,1,1 },
										const std::string & texture_path = "../../assets/textures/default.tga",
										const std::map<std::string, Variant> & variants = std::map<std::string, Variant>());

	public:

		/**
		 * @brief Constructor de Material
		 * 
		 * @param shader_program shader
		 */
		Material(const std::shared_ptr<Shader_Program>& shader_program)
			:shader(shader_program)
		{}

		/**
		 * @brief Constructor de Material
		 * 
		 * @param shader_name nombre del shader
		 * @param vertex_path ruta del vertex shader
		 * @param fragment_path ruta del fragment shader
		 * @param texture_path ruta a la textura
		 * @param variants mapa de variables uniformes
		 */
		Material(const std::string & shader_name,
				const std::string & vertex_path,
				const std::string & fragment_path,
				const std::string & texture_path,
				const std::map<std::string, Variant> & variants
		);

	public:
		/**
		 * @brief Indica a OpenGL que se va a utilizar el material
		 * 
		 */
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
