#ifndef MODEL_HEADER
#define MODEL_HEADER

#include "Mesh.hpp"
#include "Material.hpp"

#include <vector>


namespace example
{
	class Model
	{
		struct Piece
		{
			std::shared_ptr<Mesh> mesh;
			std::shared_ptr<Material> material;
		};

	private:
		std::vector<Piece> pieces;

	public:
		Model(const std::string & path, const std::string & text_path);

		Model();

	public:

		void add_piece(std::shared_ptr<Mesh> mesh, std::shared_ptr<Material> mat);

		void update();
		void render();

	private:
		bool load(const std::string & path, const std::string & text_path);
	};
}


#endif

