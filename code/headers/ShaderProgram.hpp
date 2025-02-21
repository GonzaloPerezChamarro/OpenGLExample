/**
 * @file ShaderProgram.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class of a Shader Program
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
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
		/* If of the shader program */
		GLuint id;

		/* Flag that indicates if the link was succeded */
		bool link_completed;

		/* Error log */
		std::string log;

	private:
		/* Map of shaders. Factory */
		static std::map<std::string, std::shared_ptr<Shader_Program>> factory;

	public:
		/**
		 * @brief Creates a new shader program
		 * @param name Name of the sahder
		 * @param vertex_shader_path path to the vertex shader
		 * @param fragment_shader_path path tot eh fragment shader
		 * @return std::shared_ptr<Shader_Program> 
		 */
		static std::shared_ptr<Shader_Program> create_shader(const std::string & name, const std::string & vertex_shader_path, const std::string & fragment_shader_path);
		
		/* Returns a shader program from its name if it already exists. Otherwise, it creates a new one*/
		static std::shared_ptr<Shader_Program> get_shader(const std::string & name);

		/* Constructor */
		Shader_Program()
		{
			id = glCreateProgram();
			link_completed = false;
			assert(id != 0);
		}

		/* Destructor */
		~Shader_Program()
		{
			glDeleteProgram(id);
			id = 0;
		}
		
		/* Copy constructor */
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

		void use() const 
		{
			assert(is_usable());
			glUseProgram(id);
		}
		
		bool link();

		/* Returns the id (location) of a uniform variable of a shader from its name (char array) */
		GLint get_uniform_location(const char* name)
		{
			assert(is_usable());

			GLint uniform_location = glGetUniformLocation(id, name);

			assert(uniform_location != -1);

			return uniform_location;
		}

		 /* Returns the id (location) of a uniform variable of a shader from its name (string) */
		GLint get_location_by_name(const std::string& name) const
		{
			GLint location = glGetUniformLocation(id, name.c_str());

			GLenum e = glGetError();
			assert(e == GL_NO_ERROR);

			return location;
		}

		 /* Returns the id (location) of a vertex attribute of a shader from its name */
		GLint get_vertex_attrib_location(const char * identifier)
		{
			assert(is_usable());

			GLint attrib_id = glGetAttribLocation(id, identifier);

			assert(attrib_id != -1);

			return attrib_id;
		}

		/* Returns the error log */
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
	};
}

#endif
