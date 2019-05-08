#ifndef VERTEX_ARRAY_OBJECT_HEADER
#define VERTEX_ARRAY_OBJECT_HEADER


#include "VertexBufferObject.hpp"
#include "OpenGL.hpp"

#include <list>
#include <memory>

namespace example
{
	class Vertex_Array_Object
	{
	private:
		typedef std::shared_ptr <Vertex_Buffer_Object> Sh_VBO;
		typedef std::list<Sh_VBO> VBO_List;

		GLuint id;
		GLenum error;

		VBO_List vbo_list;

	public:

		struct Vertex_Attribute_Information
		{
			Sh_VBO vbo;
			GLuint attribute_location;
			GLint components_count;
			GLenum component_type;
		};

	public:
		Vertex_Array_Object
		(
			const std::initializer_list<Vertex_Attribute_Information> & vertex_attribute_information_list,
			const std::shared_ptr< Vertex_Buffer_Object > & index_vbo = std::shared_ptr< Vertex_Buffer_Object >()
		);

		Vertex_Array_Object() {
			glGenVertexArrays(1, &id);
			error = glGetError();
			assert(error == GL_NO_ERROR);
		}

		~Vertex_Array_Object()
		{
			glDeleteVertexArrays(1, &id);
		}

	private:

		Vertex_Array_Object(const Vertex_Array_Object &);

	public:

		bool is_ok() const
		{
			return error == GL_NO_ERROR;
		}

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

