
#include "ShaderProgram.hpp"

namespace example
{
	bool Shader_Program::link()
	{

		glLinkProgram(id);

		GLint succeeded = GL_FALSE;
		glGetProgramiv(id, GL_LINK_STATUS, &succeeded);

		if (!succeeded)
		{
			GLint log_length;

			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &log_length);

			if (log_length > 0)
			{
				log.resize(log_length);

				glGetShaderInfoLog(id, log_length, NULL, &log.front());
			}

			assert(false);
		}

		return(link_completed = (succeeded != GL_FALSE));
	}
}