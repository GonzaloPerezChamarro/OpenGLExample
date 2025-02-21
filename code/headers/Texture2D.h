/**
 * @file Texture2D.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Child class of Texture.h that represents a Texture 2D
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef TEXTURE_2D_HEADER
#define TEXTURE_2D_HEADER


#include "Texture.h"
#include "OpenGL.h"

#include <map>
#include <string>

namespace example
{
	class Texture2D : public Texture
	{
	private:
		/* Map of textures. Factory*/
		static std::map<std::string, std::shared_ptr<Texture>> factory;

	public:
		/* Returns a texture by its path if it already exists. Otherwise, it creates a new one. */
		static std::shared_ptr<Texture> get_texture(const std::string & path,
			Parameter wrap = Parameter::REPEAT,
			Parameter filter = Parameter::MIPMAP_LINEAR_FILTER);

	public:
		/* Constructor */
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

				// It set the texture colors to memory
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

		/* Destructor */
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


		/* Loads a texture from a file */
		std::shared_ptr<Texture> load_texture(const std::string & path, Parameter w = Parameter::CLAMP_TO_EDGE, Parameter f = Parameter::MIPMAP_LINEAR_FILTER) override;
	};
}
#endif