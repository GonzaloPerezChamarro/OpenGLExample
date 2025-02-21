/**
 * @file VertexArrayObject.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class of a vertex array object
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef VERTEX_ARRAY_OBJECT_HEADER
#define VERTEX_ARRAY_OBJECT_HEADER


#include "VertexBufferObject.hpp"
#include "OpenGL.hpp"

#include <list>
#include <memory>
#include <assert.h>

namespace example
{
	class Vertex_Array_Object
	{
	private:
		typedef std::shared_ptr <Vertex_Buffer_Object> Sh_VBO;
		typedef std::list<Sh_VBO> VBO_List;

		/* Id of vao */
		GLuint id;

		/* Open GL error*/
		GLenum error;

		/* List of vertex buffer objects*/
		VBO_List vbo_list;

	public:
		/* Struct data of a vertex*/
		struct Vertex_Attribute_Information
		{
			Sh_VBO vbo;
			GLuint attribute_location;
			GLint components_count;
			GLenum component_type;
		};

	public:
		/* Constructor */
		Vertex_Array_Object
		(
			const std::initializer_list<Vertex_Attribute_Information> & vertex_attribute_information_list,
			const std::shared_ptr< Vertex_Buffer_Object > & index_vbo = std::shared_ptr< Vertex_Buffer_Object >()
		);

		/* Constructor */
		Vertex_Array_Object() {
			glGenVertexArrays(1, &id);
			error = glGetError();
			assert(error == GL_NO_ERROR);
		}

		/* Destructor */
		~Vertex_Array_Object()
		{
			glDeleteVertexArrays(1, &id);
		}

	private:
		/* Copy constructor */
		Vertex_Array_Object(const Vertex_Array_Object &);

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

		void bind() const
		{
			glBindVertexArray(id);
		}

		void unbind() const
		{
			glBindVertexArray(0);
		}
	};
}

#endif // !VERTEX_ARRAY_OBJECT_HEADER

