/**
 * @file OpenGL.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief File for initializing OpenGL
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
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
	/* This method must be called to initialize OpenGl on the project */
	bool init_opengl_extensions();
}
#endif // !OPENGL_HEADER

