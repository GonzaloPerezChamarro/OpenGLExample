
#include "View.hpp"
#include <SFML/OpenGL.hpp>

#include "Cube.hpp"
#include "Plane.hpp"
#include "ElevationMesh.hpp"
#include "ShaderProgram.hpp"
#include "Material.hpp"
#include "Framebuffer.hpp"
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
		Shader_Program::create_shader("postprocess", "../../assets/shaders/vertex/postprocessVertex", "../../assets/shaders/fragment/postprocessFragment");
		projection_matrix = glm::perspective(glm::radians(75.f), (float)width / height, 0.3f, 1000.f);

		framebuffer = new Framebuffer(width, height, "postprocess");
		framebuffer->build();

		create_scene();

	}

	void View::update(float deltaTime)
	{
		camera->move(camera->get_camera_front() * camera_direction.y, 10.f * deltaTime);
		camera->move(glm::normalize(glm::cross(camera->get_camera_front(), camera->get_camera_up())) * camera_direction.x, 10.f * deltaTime);


		models_map["texturedCube"]->get_transform()->rotate(glm::vec3(0, 15 * deltaTime, 0));
		models_map["childCube"]->get_transform()->rotate(glm::vec3(0, 0, 20 * deltaTime));
		//models_map["childCube3"]->get_transform()->rotate(glm::vec3(10 * deltaTime, 0,0));

		for (auto & model : models_map)
		{
			model.second->update(deltaTime);
		}
	}

	void View::render()
	{
		glClearColor(0, 1, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		if(postprocess_active)
			framebuffer->bind();
		
		skybox->render(*camera);

		light->render(*camera);

		for (auto & model : models_map)
		{
			model.second->render(camera);
		}
		
		if(postprocess_active)
			framebuffer->render();
	}

	void View::create_scene()
	{

		std::shared_ptr<Cube> cube(new Cube);
		std::shared_ptr<Model> new_model(new Model(glm::vec3(5.f, 10.f, -15.f), glm::vec3(0, 0, 0), glm::vec3(0.5f, 0.5f, 0.5f)));
		new_model->add_piece(cube, Material::get("lightShader", "../../assets/shaders/vertex/pointLightVertex", "../../assets/shaders/fragment/pointLightFragment", glm::vec3(1, 1, 1), "../../assets/textures/wood-crate-1.tga"));
		models_map["texturedCube"] = new_model;

		std::shared_ptr<Cube> c(new Cube);
		std::shared_ptr<Model> new_c(new Model(glm::vec3(0.f, 10.f, 0.f),glm::vec3(0,0,0), glm::vec3(1.f, 1.f, 1.f), new_model.get()));
		new_c->add_piece(c, Material::get("cubeShader", "../../assets/shaders/vertex/cubeVertexShader", "../../assets/shaders/fragment/cubeFragmentShader"));
		models_map["childCube"] = new_c;

		std::shared_ptr<Cube> cube3(new Cube);
		std::shared_ptr<Model> new_cube(new Model(glm::vec3(5.f, 0.f, 0.f), glm::vec3(0, 0, 0), glm::vec3(1.f, 1.f, 1.f), new_c.get()));
		new_cube->add_piece(cube3, Material::get("lightShader", "../../assets/shaders/vertex/pointLightVertex", "../../assets/shaders/fragment/pointLightFragment", glm::vec3(0, 1, 1)));
		models_map["childCube3"] = new_cube;


		std::shared_ptr<Plane> plane(new Plane(16, 16));
		std::shared_ptr<Model> new_plane(new Model(glm::vec3(-5.f, -1.f, -5.f)));
		new_plane->add_piece(plane, Material::get("cubeShader", "../../assets/shaders/vertex/cubeVertexShader", "../../assets/shaders/fragment/cubeFragmentShader"));
		models_map["plane"] = new_plane;


		std::shared_ptr<Elevation_Mesh> terrain(new Elevation_Mesh("../../assets/heightmap/heightmap.tga", 10, 10));
		std::shared_ptr<Model> new_terrain(new Model(glm::vec3(-20.f, -5.f, -20.f)));
		new_terrain->add_piece(terrain, Material::get("cubeShader", "../../assets/shaders/vertex/cubeVertexShader", "../../assets/shaders/fragment/cubeFragmentShader"));
		models_map["terrain"] = new_terrain;


		std::shared_ptr<Mesh_Obj> obj(new Mesh_Obj("../../assets/models/Cube_obj.obj"));
		std::shared_ptr<Model> obj_model(new Model(glm::vec3(-10.f, 10.f, -10.f), glm::vec3(0, 0, 0), glm::vec3(1.f, 1.f, 1.f)));
		obj_model->add_piece(obj, Material::get("lightShader", "../../assets/shaders/vertex/pointLightVertex", "../../assets/shaders/fragment/pointLightFragment",glm::vec3(1,1,1), "../../assets/textures/Cube_diffuse.tga"));
		models_map["cubeObj"] = obj_model;


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
			case sf::Keyboard::P:
				postprocess_active = !postprocess_active;
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


}