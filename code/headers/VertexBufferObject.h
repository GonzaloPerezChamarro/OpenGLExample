/**
 * @file VertexBufferObject.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class of a vertex buffer object
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef VERTEX_BUFFER_OBJECT_HEADER
#define VERTEX_BUFFER_OBJECT_HEADER

#include "OpenGL.h"

namespace example
{
	class Vertex_Buffer_Object
	{
	private:
		/* If of the vbo */
		GLuint id;

		/* Type */
		GLenum target;

		/* Type of saved element */
		GLenum element_type;

		/* OpenGL error */
		GLenum error;


	public:
		/* Enum that matches to OpenGl types*/
		enum class Target
		{
			VBO = GL_ARRAY_BUFFER,
			EAB = GL_ELEMENT_ARRAY_BUFFER
		};

		/* Constructors */
		Vertex_Buffer_Object(const GLbyte   * data, size_t size, Target target = Target::VBO) : element_type(GL_BYTE), target(GLenum(target)) { create(data, size); }
		Vertex_Buffer_Object(const GLubyte  * data, size_t size, Target target = Target::VBO) : element_type(GL_UNSIGNED_BYTE), target(GLenum(target)) { create(data, size); }
		Vertex_Buffer_Object(const GLshort  * data, size_t size, Target target = Target::VBO) : element_type(GL_SHORT), target(GLenum(target)) { create(data, size); }
		Vertex_Buffer_Object(const GLushort * data, size_t size, Target target = Target::VBO) : element_type(GL_UNSIGNED_SHORT), target(GLenum(target)) { create(data, size); }
		Vertex_Buffer_Object(const GLint    * data, size_t size, Target target = Target::VBO) : element_type(GL_INT), target(GLenum(target)) { create(data, size); }
		Vertex_Buffer_Object(const GLuint   * data, size_t size, Target target = Target::VBO) : element_type(GL_UNSIGNED_INT), target(GLenum(target)) { create(data, size); }
		Vertex_Buffer_Object(const GLfloat  * data, size_t size, Target target = Target::VBO) : element_type(GL_FLOAT), target(GLenum(target)) { create(data, size); }

		/* Destructor */
		~Vertex_Buffer_Object()
		{
			glDeleteBuffers(1, &id);
		}

	public:
		/* Returns true if there was no error */
		bool is_ok() const
		{
			return error == GL_NO_ERROR;
		}

		/* Returns the OpenGL error */
		GLenum get_error() const
		{
			return error;
		}

		/* Returns the element type*/
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
		/* Copy constructor */
		Vertex_Buffer_Object(const Vertex_Buffer_Object &);

		/* Creates a vbo */
		void create(const void * data, size_t size);
	};
}

#endif // !VERTEX_BUFFER_OBJECT_HEADER

