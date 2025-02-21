
#include "VertexBufferObject.h"

namespace example
{
	void Vertex_Buffer_Object::create(const void * data, size_t size)
	{
		glGenBuffers(1, &id);
		bind();
		glBufferData(target, size, data, GL_STATIC_DRAW);
		error = glGetError();
		// unbind();
	}
}