/**
 * @file Skybox.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase Skybox
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef SKYBOX_HEADER
#define SKYBOX_HEADER

#include "Camera.h"
#include "Cubemap.h"
#include "ShaderProgram.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"

namespace example
{
	class Skybox
	{
	private:
		/* Vertex Array Object*/
		std::shared_ptr<Vertex_Array_Object> vao;

		/* Vertex Buffer Object */
		std::shared_ptr<Vertex_Buffer_Object> vbo;

		/* If of the view matrix */
		GLint model_view_matrix_id;

		/* Id of the projection matrix */
		GLint projection_matrix_id;

		/* Cubemap texture*/
		Cubemap cubemap;

		/* Shader of the skybox */
		std::shared_ptr<Shader_Program> shader;

	public:
		/**
		 * @brief Constructor
		 * @param path Path of the cubemap
		 */
		Skybox(const std::string & path);

		/* Destructor */
		~Skybox() {};

		/* Renders the skybox */
		void render(const Camera & camera);
	};
}

#endif
