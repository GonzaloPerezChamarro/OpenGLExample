/**
 * @file Variant.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class of a variant, a non type varialbe
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "OpenGL.h"


namespace example
{
	struct Variant
	{
		enum Type
		{
			INT,
			FLOAT,
			UINT,
			VEC2,
			VEC3,
			VEC4,
			BOOL
		}type;

		union Value
		{
			GLint integer;
			GLuint uinteger;
			GLfloat f;

			GLfloat vec2[2];
			GLfloat vec3[3];
			GLfloat vec4[4];
		}
		value;

		GLint id;
	};
}
