
#include "View.hpp"
#include <SFML/OpenGL.hpp>

#include "Cube.hpp"
#include "Plane.hpp"
#include "ElevationMesh.hpp"
#include "ShaderProgram.hpp"
#include "Material.hpp"


namespace example
{
	View::View(Camera & camera, unsigned width, unsigned height)
		:camera(&camera), width(width), height(height),
		skybox(new Skybox("../../assets/skybox/")), cube(new Cube),
		light(new Light(glm::vec3(5.f,2.f,12.f), glm::vec3(1.f,1.f,1.f)))
	{
		glEnable(GL_DEPTH_TEST);//z-buffer
		glEnable(GL_CULL_FACE);// BackFace Culling
		glCullFace(GL_BACK);

		//AA
		/*glEnable(GL_BLEND);
		glEnable(GL_LINE_SMOOTH);
		glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);*/
		
		create_scene();

		Shader_Program::create_shader("cubeShader", "../../assets/shaders/vertex/cubeVertexShader", "../../assets/shaders/fragment/cubeFragmentShader");
		projection_matrix = glm::perspective(glm::radians(75.f), (float)width / height, 0.3f, 1000.f);

	}

	void View::update(float deltaTime)
	{
		//Update models ....

		camera->move(camera->get_camera_front() * camera_direction.y, 10.f * deltaTime);
		camera->move(glm::normalize(glm::cross(camera->get_camera_front(), camera->get_camera_up())) * camera_direction.x, 10.f * deltaTime);
	}

	void View::render()
	{
		glClearColor(0, 1, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		auto light_shader = Shader_Program::get_shader("lightShader");
		
		//Ejemplo cubo normal
		/*
		std::shared_ptr<Shader_Program> shader = Shader_Program::get_shader("cubeShader");

		skybox->render(*camera);
		
		model_view_matrix = glm::mat4();
		model_view_matrix = camera->get_view();
		projection_matrix = camera->get_projection();

		model_view_matrix = glm::translate(model_view_matrix, glm::vec3(5.f, 10.f, -15.f));
		model_view_matrix = glm::scale(model_view_matrix, glm::vec3(0.5f, 0.5f, 0.5f));


		shader->use();
		
		GLint m_id = shader->get_uniform_location("model_view_matrix");
		GLint p_id = shader->get_uniform_location("projection_matrix");

		glUniformMatrix4fv(m_id, 1, GL_FALSE, glm::value_ptr((model_view_matrix)));
		glUniformMatrix4fv(p_id, 1, GL_FALSE, glm::value_ptr((projection_matrix)));

		cube->render();*/

		skybox->render(*camera);

		for (auto & model : models)
		{
			model->render(camera);
		}
		
	}

	void View::handler(sf::Event & e)
	{

		switch (e.type)
		{
		case sf::Event::MouseMoved:

			camera->rotate(e.mouseMove.x, e.mouseMove.y);
			break;

		case sf::Event::KeyPressed:
		{
			switch (e.key.code)
			{
			case sf::Keyboard::W:
				camera_direction.y = 1;
				break;
			case sf::Keyboard::S:
				camera_direction.y = -1;
				break;
			case sf::Keyboard::A:
				camera_direction.x = -1;
				break;
			case sf::Keyboard::D:
				camera_direction.x = 1;
				break;
			}
		}
		break;

		case sf::Event::KeyReleased:
		{

			switch (e.key.code)
			{
			case sf::Keyboard::W:
				camera_direction.y = 0;
				break;
			case sf::Keyboard::S:
				camera_direction.y = 0;
				break;
			case sf::Keyboard::A:
				camera_direction.x = 0;
				break;
			case sf::Keyboard::D:
				camera_direction.x = 0;
				break;
			}
		}
		
		break;
		}
	}

	void View::create_scene()
	{

		std::shared_ptr<Cube> cube(new Cube);
		std::shared_ptr<Model> new_model(new Model(glm::vec3(5.f, 10.f, -15.f), glm::vec3(0.5f, 0.5f, 0.5f)));
		new_model->add_piece(cube, Material::get("cubeShader", "../../assets/shaders/vertex/cubeVertexShader", "../../assets/shaders/fragment/cubeFragmentShader"));
		models.push_back(new_model);

		std::shared_ptr<Cube> c(new Cube);
		std::shared_ptr<Model> new_c(new Model(glm::vec3(5.f, 10.f, -12.f), glm::vec3(0.5f, 0.5f, 0.5f)));
		new_c->add_piece(c, Material::get("cubeShader", "../../assets/shaders/vertex/cubeVertexShader", "../../assets/shaders/fragment/cubeFragmentShader"));
		models.push_back(new_c);

		std::shared_ptr<Plane> plane(new Plane(10, 10));
		std::shared_ptr<Model> new_plane(new Model(glm::vec3(-5.f, -1.f, -5.f)));
		new_plane->add_piece(plane, Material::get("cubeShader", "../../assets/shaders/vertex/cubeVertexShader", "../../assets/shaders/fragment/cubeFragmentShader"));
		models.push_back(new_plane);

		std::shared_ptr<Elevation_Mesh> terrain(new Elevation_Mesh("../../assets/heightmap/heightmap.tga", 10, 10));
		std::shared_ptr<Model> new_terrain(new Model(glm::vec3(-20.f, -5.f, -20.f)));
		new_terrain->add_piece(terrain, Material::get("cubeShader", "../../assets/shaders/vertex/cubeVertexShader", "../../assets/shaders/fragment/cubeFragmentShader"));
		models.push_back(new_terrain);

	}


}