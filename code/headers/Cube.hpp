#ifndef CUBE_HEADER
#define CUBE_HEADER



#include "Mesh.hpp"


namespace example
{
	class Cube :public Mesh
	{
	private:

		static const GLfloat vertex[];
		static const GLfloat texcoord[];
		static const GLfloat normals[];
		static const GLubyte indices[];

	public:
		Cube();

	public:
		void render() override;
	};


}

#endif
