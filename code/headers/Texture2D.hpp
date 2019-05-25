/**
 * @file Texture2D.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase de textura 2D, hija de Texture.hpp
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef TEXTURE_2D_HEADER
#define TEXTURE_2D_HEADER


#include "Texture.hpp"
#include "OpenGL.hpp"

#include <map>
#include <string>

namespace example
{
	class Texture2D : public Texture
	{
	private:
		/**
		 * @brief Mapa de texturas/factory
		 * 
		 */
		static std::map<std::string, std::shared_ptr<Texture>> factory;

	public:
		/**
		 * @brief Devuelve la textura segun su nombre en caso de que exista. SI no, crea una nueva.
		 * 
		 * @param path 
		 * @param wrap 
		 * @param filter 
		 * @return std::shared_ptr<Texture> 
		 */
		static std::shared_ptr<Texture> get_texture(const std::string & path,
			Parameter wrap = Parameter::REPEAT,
			Parameter filter = Parameter::MIPMAP_LINEAR_FILTER);

	public:
		/**
		 * @brief Constructor de Texture 2 D
		 * 
		 * @param path ruta de textura
		 * @param w wrap
		 * @param f filter
		 */
		Texture2D(const std::string & path, Parameter w = Parameter::CLAMP_TO_EDGE, Parameter f = Parameter::MIPMAP_LINEAR_FILTER)
		{
			std::shared_ptr<Texture> temp = load_texture(path, w, f);

			if (temp.get() != 0) 
			{
				glEnable(GL_TEXTURE_2D);
				glGenTextures(1, &id);
				glBindTexture(GL_TEXTURE_2D, id);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

				// Se suben los colores de la textura a la memoria de v�deo:

				glTexImage2D
				(
					GL_TEXTURE_2D,
					0,
					GL_RGBA,
					temp->get_width(),
					temp->get_height(),
					0,
					GL_RGBA,
					GL_UNSIGNED_BYTE,
					temp->colors()
				);
			}

		}

		~Texture2D();

	public:
		void bind() override
		{
			glBindTexture(GL_TEXTURE_2D, id);
		}

		void unbind() override
		{
			glBindTexture(GL_TEXTURE_2D, 0);
		}

		void set_wrap(Parameter parameter) override
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, parameter);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, parameter);
		}

		void set_filter(Parameter parameter) override
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, parameter);

			if (parameter == NEAR_PIXEL_FILTER || parameter == MIPMAP_NEAR_PIXEL_FILTER)
			{
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, NEAR_PIXEL_FILTER);
			}
			else if (parameter == LINEAR_FILTER || parameter == MIPMAP_LINEAR_FILTER)
			{
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, LINEAR_FILTER);
			}

			if (parameter == MIPMAP_LINEAR_FILTER || parameter == MIPMAP_NEAR_PIXEL_FILTER)
			{
				glGenerateMipmap(GL_TEXTURE_2D);
			}
		}


		/**
		 * @brief Carga la textura de un archivo
		 * 
		 * @param path ruta de la textura
		 * @param w wrap
		 * @param f filter
		 * @return std::shared_ptr<Texture> 
		 */
		std::shared_ptr<Texture> load_texture(const std::string & path, Parameter w = Parameter::CLAMP_TO_EDGE, Parameter f = Parameter::MIPMAP_LINEAR_FILTER) override;

	};

}
#endif