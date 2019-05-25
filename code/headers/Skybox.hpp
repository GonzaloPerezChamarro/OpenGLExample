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

#include "Camera.hpp"
#include "Cubemap.hpp"
#include "ShaderProgram.hpp"
#include "VertexArrayObject.hpp"
#include "VertexBufferObject.hpp"

namespace example
{
	class Skybox
	{
	private:
		/**
		 * @brief Vertex Array Object
		 * 
		 */
		std::shared_ptr<Vertex_Array_Object> vao;

		/**
		 * @brief Vertex Buffer Object
		 * 
		 */
		std::shared_ptr<Vertex_Buffer_Object> vbo;

		/**
		 * @brief Id de la matriz de camara
		 * 
		 */
		GLint model_view_matrix_id;

		/**
		 * @brief Id de la matriz de proyeccion
		 * 
		 */
		GLint projection_matrix_id;

		/**
		 * @brief Textura cubemap del skybox
		 * 
		 */
		Cubemap cubemap;

		/**
		 * @brief Shader del skybox
		 * 
		 */
		std::shared_ptr<Shader_Program> shader;

	public:
		/**
		 * @brief Constructor de Skybox
		 * 
		 * @param path 
		 */
		Skybox(const std::string & path);

		/**
		 * @brief Destructor de Skybox
		 * 
		 */
		~Skybox();

		/**
		 * @brief renderiza el skybox en pantalla
		 * 
		 * @param camera 
		 */
		void render(const Camera & camera);
	};
}

#endif
