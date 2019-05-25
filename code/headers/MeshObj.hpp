/**
 * @file MeshObj.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase hija de Mesh.hpp para carga de objectos obj
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
		 * @brief Carga el obj a partir de su ruta
		 * 
		 * @param file Ruta relativa desde el ejecutable
		 */
		void load_obj(const std::string & file);
	};
}
#endif
