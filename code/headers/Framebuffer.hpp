

#ifndef FRAMEBUFFER_HEADER
#define FRAMEBUFFER_HEADER

#include "OpenGL.hpp"

#include "ShaderProgram.hpp"

namespace example
{
	class Framebuffer
	{
	private:
		GLuint id;
		GLuint out_texture_id;

		int width;
		int height;

		std::shared_ptr<Shader_Program> shader_program;

		GLuint triangle_vbo0;
		GLuint triangle_vbo1;

	public:

		Framebuffer(int width, int height, const std::string shader);

		void bind()
		{
			glBindFramebuffer(GL_FRAMEBUFFER, id);
		}

		void unbind()
		{
			glBindFramebuffer(GL_FRAMEBUFFER, 0);

		}

		void build();
		void render();
	};
}
#endif
