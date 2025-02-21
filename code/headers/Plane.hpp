/**
 * @file Plane.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Child class of mesh.h that represents a plane
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef PLANE_HEADER
#define PLANE_HEADER


#include "Mesh.hpp"
#include "OpenGL.hpp"
#include <vector>

namespace example
{ 
	class Plane : public Mesh
	{
		std::vector<GLfloat> vertex;
		std::vector<GLfloat> normals;
		std::vector<GLfloat> texcoord;
		std::vector<GLuint> indices;

		/* Plane dimension */
		const size_t dim;
		
	public:
		/* Constructor */
		Plane(size_t width, size_t height);

	public:
		void render() override;
	};
}
#endif
