/**
 * @file ShaderProgram.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase Shader Program
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef SHADER_PROGRAM_HEADER
#define SHADER_PROGRAM_HEADER

#include "Shader.hpp"

#include "Texture.hpp"

#include <glad/glad.h>
#include <cassert>
#include <glm.hpp>
#include <map>
#include <string>

namespace example
{
	class Shader_Program
	{
	private:
		/**
		 * @brief Id del shader programm
		 * 
		 */
		GLuint id;
		/**
		 * @brief Indica si la vinculacion ha sido correcta
		 * 
		 */
		bool link_completed;

		/**
		 * @brief Texto de error/log
		 * 
		 */
		std::string log;

	private:
		/**
		 * @brief Mapa de shaders/factoria.
		 * 
		 */
		static std::map<std::string, std::shared_ptr<Shader_Program>> factory;

	public:
		/**
		 * @brief Crea un nuevo Shader Program
		 * 
		 * @param name nombre del shader
		 * @param vertex_shader_path ruta al vertex shader
		 * @param fragment_shader_path ruta al frag shader
		 * @return std::shared_ptr<Shader_Program> 
		 */
		static std::shared_ptr<Shader_Program> create_shader(const std::string & name, const std::string & vertex_shader_path, const std::string & fragment_shader_path);
		
		/**
		 * @brief Devuelve un shader a partir de su nombre si ya existe. En caso contrairo, crea uno nuevo.
		 * 
		 * @param name 
		 * @return std::shared_ptr<Shader_Program> 
		 */
		static std::shared_ptr<Shader_Program> get_shader(const std::string & name);

		/**
		 * @brief Constructor de Shader_Program
		 * 
		 */
		Shader_Program()
		{
			id = glCreateProgram();
			link_completed = false;
			assert(id != 0);
		}

		/**
		 * @brief Destructor de Shader_Program
		 * 
		 */
		~Shader_Program()
		{
			glDeleteProgram(id);
			id = 0;
		}

	public:
		/**
		 * @brief Constructor de copia de Shader_Program
		 * 
		 */
		Shader_Program(const Shader_Program &) = default;

	public:

		static void disable()
		{
			glUseProgram(0);
		}

		bool is_usable() const 
		{
			return link_completed;
		}

		void attach(const Shader & shader)
		{
			glAttachShader(id, shader);
		}
		void detach(const Shader & shader)
		{
			glDetachShader(id, shader);
		}


		bool link();

		void use() const 
		{
			assert(is_usable());
			glUseProgram(id);
		}

		/**
		 * @brief Devuelve el id (location) de una variable uniforme del shader a partir de su nombre
		 * 
		 * @param identifier 
		 * @return GLint 
		 */
		GLint get_uniform_location(const char * identifier)
		{
			assert(is_usable());

			GLint uniform_location = glGetUniformLocation(id, identifier);

			assert(uniform_location != -1);

			return uniform_location;
		}

		/**
		 * @brief Devuelve el id (location) de un atributo del shader a partir de su nombre
		 * 
		 * @param identifier 
		 * @return GLint 
		 */
		GLint get_vertex_attrib_location(const char * identifier)
		{
			assert(is_usable());

			GLint attrib_id = glGetAttribLocation(id, identifier);

			assert(attrib_id != -1);

			return attrib_id;
		}

		const std::string & get_log() const
		{
			return log;
		}

		operator GLuint () const
		{
			return (id);
		}

		void set_variant_value(GLint variant_id, const GLint     & value) { glUniform1i(variant_id, value); }
		void set_variant_value(GLint variant_id, const float     & value) { glUniform1f(variant_id, value); }
		void set_variant_value(GLint variant_id, const glm::vec2  & vector) { glUniform2f(variant_id, vector[0], vector[1]); }
		void set_variant_value(GLint variant_id, const glm::vec3  & vector) { glUniform3f(variant_id, vector[0], vector[1], vector[2]); }
		void set_variant_value(GLint variant_id, const glm::vec4  & vector) { glUniform4f(variant_id, vector[0], vector[1], vector[2], vector[3]); }
		void set_variant_value(GLint variant_id, const glm::mat2 & matrix) { glUniformMatrix2fv(variant_id, 1, GL_FALSE, &matrix[0][0]); }
		void set_variant_value(GLint variant_id, const glm::mat3 & matrix) { glUniformMatrix3fv(variant_id, 1, GL_FALSE, &matrix[0][0]); }
		void set_variant_value(GLint variant_id, const glm::mat4 & matrix) { glUniformMatrix4fv(variant_id, 1, GL_FALSE, &matrix[0][0]); }

		void set_vertex_attribute(GLint attribute_id, const float    & value) { glVertexAttrib1f(attribute_id, value); }
		void set_vertex_attribute(GLint attribute_id, const glm::vec2 & vector) { glVertexAttrib2fv(attribute_id, &vector[0]); }
		void set_vertex_attribute(GLint attribute_id, const glm::vec3 & vector) { glVertexAttrib3fv(attribute_id, &vector[0]); }
		void set_vertex_attribute(GLint attribute_id, const glm::vec4 & vector) { glVertexAttrib4fv(attribute_id, &vector[0]); }

		//void set_variant_value(const std::string & name, const GLint     & value) { glUniform1i(get_location_by_name(name), value); }
		void set_variant_value(const std::string & name, const GLfloat value){ glUniform1f(get_location_by_name(name), value); }
		void set_variant_value(const std::string & name, const glm::vec2  & vector) { glUniform2f(get_location_by_name(name), vector[0], vector[1]); }
		void set_variant_value( const std::string & name, const glm::vec3  & vector) { glUniform3fv(get_location_by_name(name),1, &vector[0]); }
		void set_variant_value(const std::string & name, const glm::vec4  & vector) { glUniform4f(get_location_by_name(name), vector[0], vector[1], vector[2], vector[3]); }
		void set_variant_value(const std::string & name, const Texture & tex)
		{
			glUniform1i(get_location_by_name(name), tex.get_id() );
		}

		/**
		 * @brief Devuelve el id (location) de una variable uniforme del shader a partir de su nombre
		 * 
		 * @param identifier 
		 * @return GLint 
		 */
		GLint get_location_by_name(const std::string & name) const
		{
			GLint location = glGetUniformLocation(id, name.c_str());

			GLenum e = glGetError();
			assert(e == GL_NO_ERROR);

			return location;
		}

		
	};
}

#endif
