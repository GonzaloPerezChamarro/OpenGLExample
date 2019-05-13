
#ifndef MESH_OBJ_HEADER
#define MESH_OBJ_HEADER


#include "Mesh.hpp"

#include <string>
#include <vector>

namespace example
{
	class Mesh_Obj :public Mesh
	{
	private:

		std::vector<GLfloat> vertex;
		std::vector<GLfloat> texcoord;
		std::vector<GLfloat> normals;
		std::vector<GLubyte> indices;
		
		std::string log_error;
	public:
		Mesh_Obj(const std::string & file);

		void render() override;

	private:
		void load_obj(const std::string & file);
	};
}
#endif
