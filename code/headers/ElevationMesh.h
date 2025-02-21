/**
 * @file ElevationMesh.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase de una malla de elevacion a partir de una imagen bump.tga
 * @brief Class of a heightmap from an imagen bump.tga
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#ifndef ELEVATION_MESH_HEADER
#define ELEVATION_MESH_HEADER

#include "Mesh.h"

#include <vector>
#include <string>

namespace example
{
	class Elevation_Mesh : public Mesh
	{
	private:
		/* Array of vertex */
		std::vector<GLfloat> vertex;

		/* Array of texture coord */
		std::vector<GLfloat> normals;

		/* Array of normals */
		std::vector<GLfloat> texcoord;

		/* Array of mesh indices */
		std::vector<GLuint> indices;

	public:
		/**
		 * @brief Constructor
		 * @param path_file path to the tga file 
		 * @param width of the plane
		 * @param height (large) of the plane
		 */
		Elevation_Mesh(const std::string & path_file,unsigned width, unsigned height);

		void render() override;

	private:

		/**
		 * @brief Calculates the normal for a vertex
		 * @param width
		 * @param height
		 * @param i Vertex index (height)
		 * @param index Vertex index (width)
		 * @return glm::vec3 Normal value
		 */
		glm::vec3 calculate_normal(unsigned width, unsigned height, size_t i, size_t index);

		/* Converts a vector into a vec3 */
		std::vector<glm::vec3> convert_vec1_to_vec3(std::vector<float> & vector1) const;
	};
}
#endif
