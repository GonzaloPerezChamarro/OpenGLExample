/**
 * @file Cube.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase que representa un cubo
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef CUBE_HEADER
#define CUBE_HEADER



#include "Mesh.hpp"


namespace example
{
	class Cube :public Mesh
	{
	private:
		/**
		 * @brief Conjunto de vertices
		 * 
		 */
		static const GLfloat vertex[];

		/**
		 * @brief Conjunto de coordenadas de textura
		 * 
		 */
		static const GLfloat texcoord[];

		/**
		 * @brief Conjunto de normales
		 * 
		 */
		static const GLfloat normals[];

		/**
		 * @brief Conjunto de indices de la malla
		 * 
		 */
		static const GLubyte indices[];

	public:
		/**
		 * @brief Constructor de cubo
		 * 
		 */
		Cube();

	public:
		void render() override;
	};


}

#endif
