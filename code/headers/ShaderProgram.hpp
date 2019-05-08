

#ifndef SHADER_PROGRAM_HEADER
#define SHADER_PROGRAM_HEADER

#include "Shader.hpp"

#include <glad/glad.h>
#include <cassert>
#include <glm.hpp>

namespace example
{
	class Shader_Program
	{
	private:
		GLuint id;
		bool link_completed;
		std::string log;

	public:

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

		void setUniformValue(GLint uniform_id, const GLint     & value) { glUniform1i(uniform_id, value); }
		void setUniformValue(GLint uniform_id, const float     & value) { glUniform1f(uniform_id, value); }
		void setUniformValue(GLint uniform_id, const glm::vec2  & vector) { glUniform2f(uniform_id, vector[0], vector[1]); }
		void setUniformValue(GLint uniform_id, const glm::vec3  & vector) { glUniform3f(uniform_id, vector[0], vector[1], vector[2]); }
		void setUniformValue(GLint uniform_id, const glm::vec4  & vector) { glUniform4f(uniform_id, vector[0], vector[1], vector[2], vector[3]); }
		void setUniformValue(GLint uniform_id, const glm::mat2 & matrix) { glUniformMatrix2fv(uniform_id, 1, GL_FALSE, &matrix[0][0]); }
		void setUniformValue(GLint uniform_id, const glm::mat3 & matrix) { glUniformMatrix3fv(uniform_id, 1, GL_FALSE, &matrix[0][0]); }
		void setUniformValue(GLint uniform_id, const glm::mat4 & matrix) { glUniformMatrix4fv(uniform_id, 1, GL_FALSE, &matrix[0][0]); }

		void set_vertex_attribute(GLint attribute_id, const float    & value) { glVertexAttrib1f(attribute_id, value); }
		void set_vertex_attribute(GLint attribute_id, const glm::vec2 & vector) { glVertexAttrib2fv(attribute_id, &vector[0]); }
		void set_vertex_attribute(GLint attribute_id, const glm::vec3 & vector) { glVertexAttrib3fv(attribute_id, &vector[0]); }
		void set_vertex_attribute(GLint attribute_id, const glm::vec4 & vector) { glVertexAttrib4fv(attribute_id, &vector[0]); }



		
	};
}

#endif