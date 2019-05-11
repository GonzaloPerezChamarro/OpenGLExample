
#include "ShaderProgram.hpp"
#include "VertexShader.hpp"
#include "Fragment_Shader.hpp"

namespace example
{
	std::map<std::string, std::shared_ptr<Shader_Program>> Shader_Program::factory;

	std::shared_ptr<Shader_Program> Shader_Program::create_shader(const std::string & name, const std::string & vertex_shader_path, const std::string & fragment_shader_path)
	{
		if (factory.count(name) > 0)
			return factory[name];

		std::shared_ptr<Shader_Program> shader(new Shader_Program);
		
		shader->attach(Vertex_Shader(Shader::Source_Code::from_file(vertex_shader_path + ".shader")));
		shader->attach(Fragment_Shader(Shader::Source_Code::from_file(fragment_shader_path + ".shader")));
		shader->link();

		if (!shader->is_usable())
		{
			shader.reset();
		}
		else
		{
			factory[name] = shader;
		}

		return shader;
	}

	std::shared_ptr<Shader_Program> Shader_Program::get_shader(const std::string & name)
	{
		if (factory.count(name) > 0)
		{
			return factory[name];
		}

		return std::shared_ptr<Shader_Program>();
	}

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