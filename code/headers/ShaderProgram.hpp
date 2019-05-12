

#ifndef SHADER_PROGRAM_HEADER
#define SHADER_PROGRAM_HEADER

#include "Shader.hpp"

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
		GLuint id;
		bool link_completed;
		std::string log;

	private:

		static std::map<std::string, std::shared_ptr<Shader_Program>> factory;

	public:

		static std::shared_ptr<Shader_Program> create_shader(const std::string & name, const std::string & vertex_shader_path, const std::string & fragment_shader_path);
		static std::shared_ptr<Shader_Program> get_shader(const std::string & name);

		Shader_Program()
		{
			id = glCreateProgram();
			link_completed = false;
			assert(id != 0);
		}

		~Shader_Program()
		{
			glDeleteProgram(id);
			id = 0;
		}

	public:
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

		GLint get_uniform_location(const char * identifier)
		{
			assert(is_usable());

			GLint uniform_location = glGetUniformLocation(id, identifier);

			assert(uniform_location != -1);

			return uniform_location;
		}

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

		void set_variant_value(const std::string & name, const GLint     & value) { glUniform1i(get_location_by_name(name), value); }
		void set_variant_value(const std::string & name, const float     & value) { glUniform1f(get_location_by_name(name), value); }
		void set_variant_value(const std::string & name, const glm::vec2  & vector) { glUniform2f(get_location_by_name(name), vector[0], vector[1]); }
		void set_variant_value( const std::string & name, const glm::vec3  & vector) { glUniform3fv(get_location_by_name(name),1, &vector[0]); }
		//void set_variant_value( const std::string & name, const glm::vec3  & vector) { glUniform3f(get_location_by_name(name), vector[0], vector[1], vector[2]); }
		void set_variant_value(const std::string & name, const glm::vec4  & vector) { glUniform4f(get_location_by_name(name), vector[0], vector[1], vector[2], vector[3]); }
		void set_variant_value(const std::string & name, const glm::mat2 & matrix) { glUniformMatrix2fv(get_location_by_name(name), 1, GL_FALSE, &matrix[0][0]); }
		void set_variant_value(const std::string & name, const glm::mat3 & matrix) { glUniformMatrix3fv(get_location_by_name(name), 1, GL_FALSE, &matrix[0][0]); }
		void set_variant_value(const std::string & name, const glm::mat4 & matrix) { glUniformMatrix4fv(get_location_by_name(name), 1, GL_FALSE, &matrix[0][0]); }

		void set_vertex_attribute(const std::string & name, const float    & value) { glVertexAttrib1f(get_location_by_name(name), value); }
		void set_vertex_attribute(const std::string & name, const glm::vec2 & vector) { glVertexAttrib2fv(get_location_by_name(name), &vector[0]); }
		void set_vertex_attribute(const std::string & name, const glm::vec3 & vector) { glVertexAttrib3fv(get_location_by_name(name), &vector[0]); }
		void set_vertex_attribute(const std::string & name, const glm::vec4 & vector) { glVertexAttrib4fv(get_location_by_name(name), &vector[0]); }

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
