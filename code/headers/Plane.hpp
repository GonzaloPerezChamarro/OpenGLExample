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
		std::vector<GLubyte> indices;

		const unsigned dim;
		
	public:
		Plane(unsigned width, unsigned height);

	public:
		void render() override;
	};
}
#endif
