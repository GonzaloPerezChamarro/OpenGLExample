/**
 * @file ElevationMesh.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase de una malla de elevacion a partir de una imagen bump.tga
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#ifndef ELEVATION_MESH_HEADER
#define ELEVATION_MESH_HEADER

#include "Mesh.hpp"

#include <vector>
#include <string>

namespace example
{
	class Elevation_Mesh :public Mesh
	{
	private:
	/**
	 * @brief Vector de vertices
	 * 
	 */
		std::vector<GLfloat> vertex;

		/**
		 * @brief Vector de normales
		 * 
		 */
		std::vector<GLfloat> normals;

		/**
		 * @brief Vector de coordenadas de textura
		 * 
		 */
		std::vector<GLfloat> texcoord;

		/**
		 * @brief Vector de indices
		 * 
		 */
		std::vector<GLuint> indices;

	public:

		/**
		 * @brief Constructor de la malla de navegacion
		 * 
		 * @param path_file ruta al archivo tga
		 * @param width ancho del plano
		 * @param height largo del plano
		 */
		Elevation_Mesh(const std::string & path_file,unsigned width, unsigned height);

		void render() override;

	private:

		/**
		 * @brief Calcula las normales del vertice que recibe
		 * 
		 * @param width ancho
		 * @param height largo
		 * @param i indice del array a lo largo
		 * @param index indice del vertice dentro de su vector
		 * @return glm::vec3 valor de la normal
		 */
		glm::vec3 calculate_normal(unsigned width, unsigned height, size_t i, size_t index);

		/**
		 * @brief convierte un vector continuo en un vector de vec3
		 * 
		 * @param vector1 
		 * @return std::vector<glm::vec3> 
		 */
		std::vector<glm::vec3> convert_vec1_to_vec3(std::vector<float> & vector1);

	};
}
#endif
