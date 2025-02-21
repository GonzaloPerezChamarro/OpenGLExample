

#include "Model.h"
#include <SFML/OpenGL.hpp>
#include <memory>

namespace example
{
	Model::Model(const std::string & path, const std::string & text_path, glm::vec3 position, glm::vec3 scale)
	{
		load(path, text_path);
	}

	Model::Model(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, Model * father)
		:position(position), scale(scale), parent(father),transform(new Transform(position, rotation, scale))
	{
		if(father != nullptr)
			transform->set_parent(father->get_transform());
	}

	void Model::update(float deltaTime)
	{
		transform->update();
	}

	void Model::render(const Camera * camera)
	{
		for (auto & piece : pieces)
		{
			glm::mat4 model_view_matrix = camera->get_view();


			model_view_matrix = model_view_matrix * transform->get_matrix();

			// Use the shader
			piece.material->get_shader()->use();

			GLint m_id = piece.material->get_shader()->get_uniform_location("model_view_matrix");
			GLint p_id = piece.material->get_shader()->get_uniform_location("projection_matrix");

			glUniformMatrix4fv(m_id, 1, GL_FALSE, glm::value_ptr((model_view_matrix)));
			glUniformMatrix4fv(p_id, 1, GL_FALSE, glm::value_ptr((camera->get_projection())));

			// Texture
			if (piece.material->get_texture() != nullptr)
				piece.material->get_texture()->bind();

			// Color
			piece.material->get_shader()->set_variant_value("_Color", piece.material->get_color());

			// Render
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