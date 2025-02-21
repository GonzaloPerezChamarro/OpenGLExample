/**
 * @file MeshObj.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Child class of Mesh.h that can be loaded from a .obj file
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */


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
		/**
		 * @brief Load a .obj
		 * @param file Relative path
		 */
		void load_obj(const std::string& file);
	};
}
#endif
