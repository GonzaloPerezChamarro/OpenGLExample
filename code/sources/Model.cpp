

#include "Model.hpp"


namespace example
{
	Model::Model(const std::string & path, const std::string & text_path)
	{
		load(path, text_path);
	}

	Model::Model()
	{
	}

	void Model::add_piece(std::shared_ptr<Mesh> mesh, std::shared_ptr<Material> mat)
	{
		Piece p;
		p.mesh = mesh;
		p.material = mat;

		pieces.push_back(p);
	}

	bool Model::load(const std::string & path, const std::string & text_path)
	{
		return false;
	}
}