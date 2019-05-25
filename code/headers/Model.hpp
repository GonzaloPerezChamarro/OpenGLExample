/**
 * @file Model.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase que recoge cualquier modelo o conjunto de modelos con sus materiales correspondientes
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

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
		/**
		 * @brief Estructura que unifica una malla con un material
		 * 
		 */
		struct Piece
		{
			std::shared_ptr<Mesh> mesh;
			std::shared_ptr<Material> material;
		};
		/**
		 * @brief Posicion del modelo
		 * 
		 */
		glm::vec3 position;

		/**
		 * @brief Escala del modelo
		 * 
		 */
		glm::vec3 scale;

		/**
		 * @brief Puntero al transform del modelo
		 * 
		 */
		Transform * transform;

		/**
		 * @brief Puntero al modelo padre. Nullptr si no existe
		 * 
		 */
		Model * father;

	private:
		/**
		 * @brief Vector conjunto de piezas
		 * 
		 */
		std::vector<Piece> pieces;

	public:
		/**
		 * @brief Constructor de Model
		 * 
		 * @param path 
		 * @param text_path 
		 * @param position 
		 * @param scale 
		 */
		Model(const std::string & path, const std::string & text_path, glm::vec3 position, glm::vec3 scale = glm::vec3(1,1,1));

		/**
		 * @brief Constructor de Model
		 * 
		 * @param position 
		 * @param rotation 
		 * @param scale 
		 * @param father 
		 */
		Model(glm::vec3 position, glm::vec3 rotation = glm::vec3(0, 0, 0), glm::vec3 scale = glm::vec3(1, 1, 1), Model * father = nullptr);

	public:

		/**
		 * @brief Añade una pieza al vector de piezas
		 * 
		 * @param mesh malla
		 * @param mat material
		 */
		void add_piece(std::shared_ptr<Mesh> mesh, std::shared_ptr<Material> mat);

		/**
		 * @brief Actualiza el modelo
		 * 
		 * @param deltaTime 
		 */
		void update(float deltaTime);

		/**
		 * @brief Renderiza todas las piezas con sus materiales
		 * 
		 * @param camera 
		 */
		void render(const Camera * camera);

		glm::vec3 get_position() const { return position; }
		glm::vec3 get_scale() const { return scale; }

		Transform * get_transform()const { return transform; }

		std::shared_ptr<Material> get_material(size_t index) const { return pieces[0].material; }

	private:
		bool load(const std::string & path, const std::string & text_path);
	};
}


#endif

