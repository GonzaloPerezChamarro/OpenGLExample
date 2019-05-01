#ifndef VERTEX_BUFFER_OBJECT_HEADER
#define VERTEX_BUFFER_OBJECT_HEADER

#include "OpenGL.hpp"

namespace example
{
	class Vertex_Buffer_Object
	{
	private:
		GLuint id;
		GLenum target;
		GLenum element_type;
		GLenum error;


	public:
		enum Target
		{
			VBO = GL_ARRAY_BUFFER,
			EAB = GL_ELEMENT_ARRAY_BUFFER
		};

		Vertex_Buffer_Object(const GLbyte   * data, size_t size, Target target = VBO) : element_type(GL_BYTE), target(GLenum(target)) { create(data, size); }
		Vertex_Buffer_Object(const GLubyte  * data, size_t size, Target target = VBO) : element_type(GL_UNSIGNED_BYTE), target(GLenum(target)) { create(data, size); }
		Vertex_Buffer_Object(const GLshort  * data, size_t size, Target target = VBO) : element_type(GL_SHORT), target(GLenum(target)) { create(data, size); }
		Vertex_Buffer_Object(const GLushort * data, size_t size, Target target = VBO) : element_type(GL_UNSIGNED_SHORT), target(GLenum(target)) { create(data, size); }
		Vertex_Buffer_Object(const GLint    * data, size_t size, Target target = VBO) : element_type(GL_INT), target(GLenum(target)) { create(data, size); }
		Vertex_Buffer_Object(const GLuint   * data, size_t size, Target target = VBO) : element_type(GL_UNSIGNED_INT), target(GLenum(target)) { create(data, size); }
		Vertex_Buffer_Object(const GLfloat  * data, size_t size, Target target = VBO) : element_type(GL_FLOAT), target(GLenum(target)) { create(data, size); }

		~Vertex_Buffer_Object()
		{
			glDeleteBuffers(1, &id);
		}

	public:

		bool is_ok() const
		{
			return error == GL_NO_ERROR;
		}

		GLenum get_error() const
		{
			return error;
		}

		GLenum get_element_type() const
		{
			return element_type;
		}

		void bind() const
		{
			glBindBuffer(target, id);
		}

		void unbind() const
		{
			glBindBuffer(target, 0);
		}

	private:

		Vertex_Buffer_Object(const Vertex_Buffer_Object &);

		void create(const void * data, size_t size);

	};

}

#endif // !VERTEX_BUFFER_OBJECT_HEADER

