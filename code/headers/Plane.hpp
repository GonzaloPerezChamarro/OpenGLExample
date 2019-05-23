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

		const size_t dim;
		
	public:
		Plane(size_t width, size_t height);

	public:
		void render() override;
	};
}
#endif
