/**
 * @file Cubemap.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class of a cubemap texture
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef CUBEMAP_HEADER
#define CUBEMAP_HEADER

#include "Texture.h"

namespace example
{
	class Cubemap : public Texture
	{
	public:
		/* Constructor */
		Cubemap(const std::string& path);

		/* Destructor */
		~Cubemap();

	public:
		/* Loads a texture for the cubemap */
		std::shared_ptr<Texture> load_texture(const std::string & path);

		void bind() override 
		{
			glBindTexture(GL_TEXTURE_CUBE_MAP, id);
		}

		void unbind() override 
		{
			glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
		}
	};
}
#endif