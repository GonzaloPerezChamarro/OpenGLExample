

#include "Model.hpp"
#include <SFML/OpenGL.hpp>
#include <memory>

namespace example
{
	Model::Model(const std::string & path, const std::string & text_path, glm::vec3 position, glm::vec3 scale)
	{
		load(path, text_path);
	}

	Model::Model(glm::vec3 position, glm::vec3 scale, Model * father)
		:position(position), scale(scale), father(father)
	{

	}



	void Model::update(float deltaTime)
	{
		//nothing
	}

	void Model::render(const Camera * camera)
	{
		for (auto & piece : pieces)
		{
			glm::mat4 model_view_matrix = camera->get_view();



			if (father != nullptr)
			{
				model_view_matrix == glm::translate(model_view_matrix, father->get_position() + position);
				model_view_matrix = glm::scale(model_view_matrix, father->get_scale() * scale);

			}
			else
			{
				model_view_matrix = glm::translate(model_view_matrix, transform.get_position());
				model_view_matrix = glm::scale(model_view_matrix, transform.get_scale());

			}


			piece.material->get_shader()->use();

			GLint m_id = piece.material->get_shader()->get_uniform_location("model_view_matrix");
			GLint p_id = piece.material->get_shader()->get_uniform_location("projection_matrix");

			glUniformMatrix4fv(m_id, 1, GL_FALSE, glm::value_ptr((model_view_matrix)));
			glUniformMatrix4fv(p_id, 1, GL_FALSE, glm::value_ptr((camera->get_projection())));

			if (piece.material->get_texture() != nullptr)
				piece.material->get_texture()->bind();

			piece.material->get_shader()->set_variant_value("_Color", piece.material->get_color());

			piece.mesh->render();

			if (piece.material->get_texture() != nullptr)
				piece.material->get_texture()->unbind();

		}
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