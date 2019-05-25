/**
 * @file Framebuffer.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase Frambuffer. Se realiza el postprocesado
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
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
		/**
		 * @brief Id del frambuffer
		 * 
		 */
		GLuint id;

		/**
		 * @brief id de la textura que se genera
		 * 
		 */
		GLuint out_texture_id;

		/**
		 * @brief Ancho de la pantalla (o del postprocesado)
		 * 
		 */
		int width;

		/**
		 * @brief Alto de la pantalla (o del postprocesado)
		 * 
		 */
		int height;

		/**
		 * @brief Shader de postprocesado
		 * 
		 */
		std::shared_ptr<Shader_Program> shader_program;

		GLuint triangle_vbo0;
		GLuint triangle_vbo1;

	public:
		/**
		 * @brief Constructor de Framebuffer
		 * 
		 * @param width ancho de la pantalla (o del postprocesado)
		 * @param height alto de la pantalla (o del postprocesado)
		 * @param shader nombre del shader
		 */
		Framebuffer(int width, int height, const std::string shader);


		void bind()
		{
			glBindFramebuffer(GL_FRAMEBUFFER, id);
		}

		void unbind()
		{
			glBindFramebuffer(GL_FRAMEBUFFER, 0);

		}

		/**
		 * @brief Contruye el frambuffer
		 * 
		 */
		void build();

		/**
		 * @brief Renderiza el postprocesado
		 * 
		 */
		void render();
	};
}
#endif
