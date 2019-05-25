/**
 * @file OpenGL.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Archivo para inicializar opengl
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef OPENGL_HEADER
#define OPENGL_HEADER

#include <glad/glad.h>
#include <SFML/OpenGL.hpp>


#undef near
#undef far


namespace example
{
	/**
	 * @brief Debe llamarse a este método para inicializar opengl en el proyecto.
	 * 
	 * @return true 
	 * @return false 
	 */
	bool init_opengl_extensions();
}
#endif // !OPENGL_HEADER

