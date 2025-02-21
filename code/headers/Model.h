/**
 * @file Model.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class that represent any model or models group and their materials
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef MODEL_HEADER
#define MODEL_HEADER

#include "Mesh.h"
#include "Material.h"
#include "Camera.h"
#include "Transform.h"

#include <vector>


namespace example
{
	class Model
	{
		/* Struct that unifies a mesh and a material */
		struct Piece
		{
			std::shared_ptr<Mesh> mesh;
			std::shared_ptr<Material> material;
		};

		glm::vec3 position;
		glm::vec3 scale;

		/* Pointer to model's transform */
		Transform* transform;

		/* Pointer to parent model (if any) */
		Model* parent;

	private:
		/* Array of pieces */
		std::vector<Piece> pieces;

	public:
		/* Constructor */
		Model(const std::string & path, const std::string & text_path, glm::vec3 position, glm::vec3 scale = glm::vec3(1,1,1));

		/* Alternative constructor */
		Model(glm::vec3 position, glm::vec3 rotation = glm::vec3(0, 0, 0), glm::vec3 scale = glm::vec3(1, 1, 1), Model * father = nullptr);

	public:

		/**
		 * @brief Adds a piece to the array of pieces
		 * @param mesh Mesh of the piece
		 * @param mat Material of the piece
		 */
		void add_piece(std::shared_ptr<Mesh> mesh, std::shared_ptr<Material> mat);

		/**
		 * @brief Updates the model 
		 * @param deltaTime Delta time
		 */
		void update(float deltaTime);

		/**
		 * @brief Renders all pieces
		 * @param camera Pointer to main camera
		 */
		void render(const Camera * camera);

		glm::vec3 get_position() const { return position; }
		glm::vec3 get_scale() const { return scale; }

		Transform * get_transform()const { return transform; }

		std::shared_ptr<Material> get_material(size_t index) const { return index < pieces.size() ? pieces[index].material : nullptr; }

	private:
		bool load(const std::string & path, const std::string & text_path);
	};
}


#endif

