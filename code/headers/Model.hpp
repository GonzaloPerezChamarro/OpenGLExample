#pragma once

#include "Mesh.hpp"
#include "Material.hpp"

#include <vector>


namespace example
{
	class Model
	{
		struct Piece
		{
			Mesh mesh;
			Material material;
		};

	private:
		std::vector<Piece> pieces;

	public:
		Model(const std::string & path, const std::string & text_path);

	private:
		bool load();
	};
}
