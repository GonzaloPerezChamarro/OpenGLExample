/**
 * @file Mesh.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class that represent a mesh object
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#ifndef MESH_HEADER
#define MESH_HEADER


#include "OpenGL.hpp"
#include "VertexArrayObject.hpp"
#include "VertexBufferObject.hpp"

#include <glm.hpp>
#include <memory>

namespace example
{
	class Mesh
	{
	protected:
		/* Vertex Array Object */
		std::shared_ptr<Vertex_Array_Object> vao;

		/* Vectex buffer */
		std::shared_ptr<Vertex_Buffer_Object> vertex_buffer;

		/* Texture coord buffer */
		std::shared_ptr<Vertex_Buffer_Object> texcoord_buffer;

		/* Array of normals */
		std::shared_ptr<Vertex_Buffer_Object> normals_buffer;

		/* Array of indices */
		std::shared_ptr<Vertex_Buffer_Object> indices_buffer;

	public:
		/* Constructor by default */
		Mesh() = default;

	public:
		virtual void render() {}

		void set_vao(const std::shared_ptr<Vertex_Array_Object> & new_vao) { vao = new_vao; }

		void set_vertex(const std::shared_ptr<Vertex_Buffer_Object> & vertex) { vertex_buffer = vertex; }
		void set_texcoord(const std::shared_ptr<Vertex_Buffer_Object> & texcoord) { texcoord_buffer = texcoord; }
		void set_normals(const std::shared_ptr<Vertex_Buffer_Object> & normals) { normals_buffer = normals; }
		void set_indices(const std::shared_ptr<Vertex_Buffer_Object> & indices) { indices_buffer = indices; }
	};
}

#endif
