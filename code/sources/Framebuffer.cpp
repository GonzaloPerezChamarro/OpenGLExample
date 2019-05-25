

#include "Framebuffer.hpp"
#include <assert.h>
#include <string>

namespace example
{
	Framebuffer::Framebuffer(int width, int height,const std::string shader)
		:width(width), height(height)
	{
		shader_program = Shader_Program::get_shader(shader);
	}

	void Framebuffer::build()
	{
		//Generacion de framebuffer
		glGenFramebuffers(1, &id);
		bind();

		//Textura
		glGenTextures(1, &out_texture_id);
		glBindTexture(GL_TEXTURE_2D, out_texture_id);

		glTexImage2D
		(
			GL_TEXTURE_2D,
			0,
			GL_RGB,
			width,
			height,
			0,
			GL_RGB,
			GL_UNSIGNED_BYTE,
			0
		);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);


		glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, out_texture_id, 0);

		const GLenum draw_buffer = GL_COLOR_ATTACHMENT1;

		glDrawBuffers(1, &draw_buffer);

		assert(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE);

		unbind();

		//Quad de pantalla en el que aplicar el postprocesado
		//y sus coordenadas
		static const GLfloat triangle_positions[] =
		{
			+1.0f, -1.0f, 0.0f,
			+1.0f, +1.0f, 0.0f,
			-1.0f, +1.0f, 0.0f,
			-1.0f, +1.0f, 0.0f,
			-1.0f, -1.0f, 0.0f,
			+1.0f, -1.0f, 0.0f

		};
		
		static const GLfloat triangle_texture_uv[] =
		{
			+1.0f,  0.0f,
			+1.0f, +1.0f,
			 0.0f, +1.0f,
			 0.0f, +1.0f,
			 0.0f,  0.0f,
			 1.0f,  0.0f
		};

		glBindVertexArray(0);


		glGenBuffers(1, &triangle_vbo0);
		glBindBuffer(GL_ARRAY_BUFFER, triangle_vbo0);
		glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_positions), triangle_positions, GL_STATIC_DRAW);

		glGenBuffers(1, &triangle_vbo1);
		glBindBuffer(GL_ARRAY_BUFFER, triangle_vbo1);
		glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_texture_uv), triangle_texture_uv, GL_STATIC_DRAW);

		

	}

	void Framebuffer::render()
	{
		glBindVertexArray(0);

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		//Uso del shader de postprocesado
		shader_program->use();
		//Textura
		glBindTexture(GL_TEXTURE_2D, out_texture_id);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, triangle_vbo0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, triangle_vbo1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

		//Renderizado
		glDrawArrays(GL_TRIANGLES, 0, 6);

	}
}