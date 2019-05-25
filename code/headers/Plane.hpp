/**
 * @file Plane.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase hija de Mesh.hpp que representa un plano
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef PLANE_HEADER
#define PLANE_HEADER


#include "Mesh.hpp"
#include "OpenGL.hpp"
#include <vector>

namespace example
{ 
	class Plane :public Mesh
	{
		std::vector<GLfloat> vertex;
		std::vector<GLfloat> normals;
		std::vector<GLfloat> texcoord;
		std::vector<GLuint> indices;

		/**
		 * @brief Dimension del plano
		 * 
		 */
		const size_t dim;
		
	public:
		/**
		 * @brief Constructor
		 * 
		 * @param width Ancho del plano
		 * @param height Largo del plano
		 */
		Plane(size_t width, size_t height);

	public:
		void render() override;
	};
}
#endif
