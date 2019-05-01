#ifndef OPENGL_HEADER
#define OPENGL_HEADER

#include <glad/glad.h>
#include <SFML/OpenGL.hpp>


#undef near
#undef far


namespace example
{
	bool init_opengl_extensions()
	{
		return gladLoadGL() != 0;
	}
}
#endif // !OPENGL_HEADER

