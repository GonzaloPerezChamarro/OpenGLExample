
#ifndef MESH_OBJ_HEADER
#define MESH_OBJ_HEADER


#include "Mesh.hpp"

namespace example
{
	class Mesh_Obj :public Mesh
	{
	private:


	public:
		Mesh_Obj(std::string & file);

		void render() override;
	};
}
#endif
