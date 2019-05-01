#pragma once

#include "Mesh.hpp"
#include "Material.hpp"

#include <vector>


namespace example
{
	class Model
	{
	private:
		std::vector<std::shared_ptr<Mesh>> meshes;
		std::vector < std::shared_ptr<Material>> materials;
	public:
		Model(const std::string & path, const std::string & text_path);

	private:
		bool load();
	};
}
