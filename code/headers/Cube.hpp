/**
 * @file Cube.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class that represent a cube
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
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
		/* Array of vertex */
		static const GLfloat vertex[];

		/* Array of texture coord */
		static const GLfloat texcoord[];

		/* Array of normals */
		static const GLfloat normals[];

		/* Array of mesh indices */
		static const GLubyte indices[];

	public:
		/* Constructor */
		Cube();

	public:
		void render() override;
	};
}

#endif
