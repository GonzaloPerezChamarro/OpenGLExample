
#include "View.hpp"
#include <SFML/OpenGL.hpp>

#include "Cube.hpp"
#include "Plane.hpp"
#include "ElevationMesh.hpp"
#include "ShaderProgram.hpp"
#include "Material.hpp"
#include "MeshObj.hpp"


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
		


		Shader_Program::create_shader("cubeShader", "../../assets/shaders/vertex/cubeVertexShader", "../../assets/shaders/fragment/cubeFragmentShader");
		Shader_Program::create_shader("lightShader", "../../assets/shaders/vertex/pointLightVertex", "../../assets/shaders/fragment/pointLightFragment");
		projection_matrix = glm::perspective(glm::radians(75.f), (float)width / height, 0.3f, 1000.f);

		create_scene();

	}

	void View::update(float deltaTime)
	{
		//Update models ....

		camera->move(camera->get_camera_front() * camera_direction.y, 10.f * deltaTime);
		camera->move(glm::normalize(glm::cross(camera->get_camera_front(), camera->get_camera_up())) * camera_direction.x, 10.f * deltaTime);

		//for (auto & model : models)
		//{
		//	model->update(deltaTime);
		//}

		for (auto & model : models_map)
		{
			model.second->update(deltaTime);
		}
	}

	void View::render()
	{

		//std::shared_ptr<Texture> texture(new Texture2D("../../assets/textures/cube.tga"));

		glClearColor(0, 1, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		light->render(*camera);
		


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

		for (auto & model : models_map)
		{
			model.second->render(camera);
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
		new_model->add_piece(cube, Material::get("lightShader", "../../assets/shaders/vertex/pointLightVertex", "../../assets/shaders/fragment/pointLightFragment", "../../assets/textures/wood-crate-1.tga"));
		models_map["texturedCube"] = new_model;

		//std::shared_ptr<Cube> c(new Cube);
		//std::shared_ptr<Model> new_c(new Model(glm::vec3(0.f, 2.f, 0.f), glm::vec3(1.f, 1.f, 1.f), new_model.get()));
		//new_c->add_piece(c, Material::get("cubeShader", "../../assets/shaders/vertex/cubeVertexShader", "../../assets/shaders/fragment/cubeFragmentShader"));
		//models_map["childCube"] = new_c;


		std::shared_ptr<Plane> plane(new Plane(50, 50));
		std::shared_ptr<Model> new_plane(new Model(glm::vec3(-5.f, -1.f, -5.f)));
		new_plane->add_piece(plane, Material::get("cubeShader", "../../assets/shaders/vertex/cubeVertexShader", "../../assets/shaders/fragment/cubeFragmentShader"));
		models_map["plane"] = new_plane;


		std::shared_ptr<Elevation_Mesh> terrain(new Elevation_Mesh("../../assets/heightmap/heightmap.tga", 10, 10));
		std::shared_ptr<Model> new_terrain(new Model(glm::vec3(-20.f, -5.f, -20.f)));
		new_terrain->add_piece(terrain, Material::get("cubeShader", "../../assets/shaders/vertex/cubeVertexShader", "../../assets/shaders/fragment/cubeFragmentShader"));
		models_map["terrain"] = new_terrain;


		std::shared_ptr<Mesh_Obj> obj(new Mesh_Obj("../../assets/models/Cube_obj.obj"));
		std::shared_ptr<Model> obj_model(new Model(glm::vec3(-10.f, 10.f, -10.f), glm::vec3(1.f, 1.f, 1.f)));
		obj_model->add_piece(obj, Material::get("lightShader", "../../assets/shaders/vertex/pointLightVertex", "../../assets/shaders/fragment/pointLightFragment", "../../assets/textures/Cube_diffuse.tga"));
		models_map["cubeObj"] = obj_model;


	}


}