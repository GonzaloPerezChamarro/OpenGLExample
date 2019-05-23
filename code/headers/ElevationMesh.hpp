
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
		std::vector<GLfloat> vertex;
		std::vector<GLfloat> normals;
		std::vector<GLfloat> texcoord;
		std::vector<GLuint> indices;

	public:

		Elevation_Mesh(const std::string & path_file,unsigned width, unsigned height);

		void render() override;

	private:

		glm::vec3 calculate_normal(unsigned width, unsigned height, size_t i, size_t index);

		std::vector<glm::vec3> convert_vec1_to_vec3(std::vector<float> & vector1);

	};
}
#endif
