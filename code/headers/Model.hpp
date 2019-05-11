#ifndef MODEL_HEADER
#define MODEL_HEADER

#include "Mesh.hpp"
#include "Material.hpp"
#include "Camera.hpp"

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

		glm::vec3 position;
		glm::vec3 scale;

	private:
		std::vector<Piece> pieces;

	public:
		Model(const std::string & path, const std::string & text_path, glm::vec3 position, glm::vec3 scale = glm::vec3(1,1,1));

		Model(glm::vec3 position, glm::vec3 scale = glm::vec3(1, 1, 1));

	public:

		void add_piece(std::shared_ptr<Mesh> mesh, std::shared_ptr<Material> mat);

		void update(float deltaTime);
		void render(const Camera * camera);

	private:
		bool load(const std::string & path, const std::string & text_path);
	};
}


#endif

