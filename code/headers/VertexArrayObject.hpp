/**
 * @file VertexArrayObject.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase Vertex Array Object
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
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

		/**
		 * @brief Id del vao
		 * 
		 */
		GLuint id;
		/**
		 * @brief Error de OpenGl
		 * 
		 */
		GLenum error;

		/**
		 * @brief Lista de Vertex Buffer Objects
		 * 
		 */
		VBO_List vbo_list;

	public:

		/**
		 * @brief Estructura de informacion del vertice
		 * 
		 */
		struct Vertex_Attribute_Information
		{
			Sh_VBO vbo;
			GLuint attribute_location;
			GLint components_count;
			GLenum component_type;
		};

	public:
		/**
		 * @brief Constructor de Vertex_Array_Object
		 * 
		 * @param vertex_attribute_information_list 
		 * @param index_vbo 
		 */
		Vertex_Array_Object
		(
			const std::initializer_list<Vertex_Attribute_Information> & vertex_attribute_information_list,
			const std::shared_ptr< Vertex_Buffer_Object > & index_vbo = std::shared_ptr< Vertex_Buffer_Object >()
		);

		/**
		 * @brief Constructor de Vertex_Array_Object
		 * 
		 */
		Vertex_Array_Object() {
			glGenVertexArrays(1, &id);
			error = glGetError();
			assert(error == GL_NO_ERROR);
		}

		/**
		 * @brief Destructor de Vertex_Array_Object
		 * 
		 */
		~Vertex_Array_Object()
		{
			glDeleteVertexArrays(1, &id);
		}

	private:
		/**
		 * @brief Constructor de copia de Vertex_Array_Object
		 * 
		 */
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

