/**
 * @file VertexBufferObject.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase Vertex Buffer Object
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef VERTEX_BUFFER_OBJECT_HEADER
#define VERTEX_BUFFER_OBJECT_HEADER

#include "OpenGL.hpp"

namespace example
{
	class Vertex_Buffer_Object
	{
	private:
	/**
	 * @brief Id del vbo
	 * 
	 */
		GLuint id;

		/**
		 * @brief Indica el tipo
		 * 
		 */
		GLenum target;

		/**
		 * @brief Indica el tipo de elemento guardado
		 * 
		 */
		GLenum element_type;

		/**
		 * @brief Error de OpenGl
		 * 
		 */
		GLenum error;


	public:
		/**
		 * @brief Indica el tipo de Vertex Buffer Object
		 * 
		 */
		enum Target
		{
			VBO = GL_ARRAY_BUFFER,
			EAB = GL_ELEMENT_ARRAY_BUFFER
		};

		//Constructores
		Vertex_Buffer_Object(const GLbyte   * data, size_t size, Target target = VBO) : element_type(GL_BYTE), target(GLenum(target)) { create(data, size); }
		Vertex_Buffer_Object(const GLubyte  * data, size_t size, Target target = VBO) : element_type(GL_UNSIGNED_BYTE), target(GLenum(target)) { create(data, size); }
		Vertex_Buffer_Object(const GLshort  * data, size_t size, Target target = VBO) : element_type(GL_SHORT), target(GLenum(target)) { create(data, size); }
		Vertex_Buffer_Object(const GLushort * data, size_t size, Target target = VBO) : element_type(GL_UNSIGNED_SHORT), target(GLenum(target)) { create(data, size); }
		Vertex_Buffer_Object(const GLint    * data, size_t size, Target target = VBO) : element_type(GL_INT), target(GLenum(target)) { create(data, size); }
		Vertex_Buffer_Object(const GLuint   * data, size_t size, Target target = VBO) : element_type(GL_UNSIGNED_INT), target(GLenum(target)) { create(data, size); }
		Vertex_Buffer_Object(const GLfloat  * data, size_t size, Target target = VBO) : element_type(GL_FLOAT), target(GLenum(target)) { create(data, size); }

		/**
		 * @brief Destructor de Vertex_Buffer_Object
		 * 
		 */
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
		/**
		 * @brief Constructor de copia de Vertex_Buffer_Object
		 * 
		 */
		Vertex_Buffer_Object(const Vertex_Buffer_Object &);

		/**
		 * @brief Crea un VBO con los datos recibidos
		 * 
		 * @param data 
		 * @param size 
		 */
		void create(const void * data, size_t size);

	};

}

#endif // !VERTEX_BUFFER_OBJECT_HEADER

