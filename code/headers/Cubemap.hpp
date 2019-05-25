/**
 * @file Cubemap.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase de textura cubemap
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef CUBEMAP_HEADER
#define CUBEMAP_HEADER

#include "Texture.hpp"

namespace example
{
	class Cubemap :public Texture
	{
	public:
		/**
		 * @brief Constructor de Cubemap
		 * 
		 * @param path 
		 */
		Cubemap(const std::string & path);

		/**
		 * @brief Destructor de Cubemap
		 * 
		 */
		~Cubemap();

	public:
		/**
		 * @brief Carga una textura para el cubemap
		 * 
		 * @param path 
		 * @return std::shared_ptr<Texture> 
		 */
		std::shared_ptr<Texture> load_texture(const std::string & path);

		/**
		 * @brief "Bindea" el cubemap
		 * 
		 */
		void bind() override 
		{
			glBindTexture(GL_TEXTURE_CUBE_MAP, id);
		}

		/**
		 * @brief "Desbindea" el cubemap
		 * 
		 */
		void unbind() override 
		{
			glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
		}


	};
}
#endif