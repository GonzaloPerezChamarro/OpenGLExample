/**
 * @file Variant.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase Variant, para el uso de variables no tipadas
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "OpenGL.hpp"


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
		}value;

		GLint id;
	};
}
