/**
 * @file Framebuffer.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class of a framebuffer, used for postprocess
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef FRAMEBUFFER_HEADER
#define FRAMEBUFFER_HEADER

#include "OpenGL.hpp"

#include "ShaderProgram.hpp"

namespace example
{
	class Framebuffer
	{
	private:
		/* Framebffer id */
		GLuint id;

		/* Id of the generated texture */
		GLuint out_texture_id;

		/* Width of the window (or postprocess) */
		int width;

		/* Height of the window (or postprocess) */
		int height;

		/* Pointer to shader */
		std::shared_ptr<Shader_Program> shader_program;

		GLuint triangle_vbo0;
		GLuint triangle_vbo1;

	public:
		/* Constructor */
		Framebuffer(int width, int height, const std::string shader);

		/* Builds the framebuffer */
		void build();

		/* Renders the postprocess */
		void render();

		void bind()
		{
			glBindFramebuffer(GL_FRAMEBUFFER, id);
		}

		void unbind()
		{
			glBindFramebuffer(GL_FRAMEBUFFER, 0);

		}
	};
}
#endif
