
#include <glad/glad.h>

namespace example
{
	bool init_opengl_extensions()
	{
		return gladLoadGL() != 0;
	}
}