#ifndef MODEL_HEADER
#define MODEL_HEADER

#include "Mesh.hpp"
#include "Material.hpp"
#include "Camera.hpp"
#include "Transform.hpp"

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

		Transform * transform;

		Model * father;

	private:
		std::vector<Piece> pieces;

	public:
		Model(const std::string & path, const std::string & text_path, glm::vec3 position, glm::vec3 scale = glm::vec3(1,1,1));

		Model(glm::vec3 position, glm::vec3 rotation = glm::vec3(0, 0, 0), glm::vec3 scale = glm::vec3(1, 1, 1), Model * father = nullptr);

	public:

		void add_piece(std::shared_ptr<Mesh> mesh, std::shared_ptr<Material> mat);

		void update(float deltaTime);
		void render(const Camera * camera);

		glm::vec3 get_position() const { return position; }
		glm::vec3 get_scale() const { return scale; }

		Transform * get_transform()const { return transform; }

	private:
		bool load(const std::string & path, const std::string & text_path);
	};
}


#endif

