

#include "glad/glad.h"
#include "Skybox.hpp"
#include "VertexShader.hpp"
#include "Fragment_Shader.hpp"
#include "glm.hpp"



namespace example
{
	namespace
	{
		const GLfloat coordinates[] =
		{
					-1.0f, +1.0f, -1.0f,
			-1.0f, -1.0f, -1.0f,
			+1.0f, -1.0f, -1.0f,
			+1.0f, -1.0f, -1.0f,
			+1.0f, +1.0f, -1.0f,
			-1.0f, +1.0f, -1.0f,
			-1.0f, -1.0f, +1.0f,
			-1.0f, -1.0f, -1.0f,
			-1.0f, +1.0f, -1.0f,
			-1.0f, +1.0f, -1.0f,
			-1.0f, +1.0f, +1.0f,
			-1.0f, -1.0f, +1.0f,
			+1.0f, -1.0f, -1.0f,
			+1.0f, -1.0f, +1.0f,
			+1.0f, +1.0f, +1.0f,
			+1.0f, +1.0f, +1.0f,
			+1.0f, +1.0f, -1.0f,
			+1.0f, -1.0f, -1.0f,
			-1.0f, -1.0f, +1.0f,
			-1.0f, +1.0f, +1.0f,
			+1.0f, +1.0f, +1.0f,
			+1.0f, +1.0f, +1.0f,
			+1.0f, -1.0f, +1.0f,
			-1.0f, -1.0f, +1.0f,
			-1.0f, +1.0f, -1.0f,
			+1.0f, +1.0f, -1.0f,
			+1.0f, +1.0f, +1.0f,
			+1.0f, +1.0f, +1.0f,
			-1.0f, +1.0f, +1.0f,
			-1.0f, +1.0f, -1.0f,
			-1.0f, -1.0f, -1.0f,
			-1.0f, -1.0f, +1.0f,
			+1.0f, -1.0f, -1.0f,
			+1.0f, -1.0f, -1.0f,
			-1.0f, -1.0f, +1.0f,
			+1.0f, -1.0f, +1.0f,
		};

		const std::string vertex_code =
			"#version 330 core\n"

			""
			"uniform mat4 model_view_matrix;"
			"uniform mat4 projection_matrix;"
			""
			"layout(location = 0) in vec3 vertex;"
			""
			"out vec3 texture_coords;"
			""
			"void main()"
			"{"
			"	texture_coords = vec3(vertex.x, -vertex.y, vertex.z);"
			"	gl_Position = projection_matrix * model_view_matrix * vec4(vertex, 1.0);"
			"}";

		const std::string fragment_code =
			"#version 330 core\n"
			""
			"in vec3 texture_coords;"
			"out vec4 color;"
			""
			"uniform samplerCube texture_cube;"
			""
			"void main()"
			"{"
			"	color = texture(texture_cube, texture_coords);"
			"}";
	}


	Skybox::Skybox(const std::string & path)
		:cubemap(path), shader(new Shader_Program)
	{
		shader->attach(Vertex_Shader(Shader::Source_Code::from_string(vertex_code)));
		shader->attach(Fragment_Shader(Shader::Source_Code::from_string(fragment_code)));

		shader->link();

		vao.reset(new Vertex_Array_Object);

		vao->bind();
		vbo.reset(new Vertex_Buffer_Object(coordinates, sizeof(coordinates)));
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, vbo->get_element_type(), GL_FALSE, 0, 0);
		vao->unbind();


	}

	void Skybox::render(const glm::mat4 & projection, const Camera & camera)
	{
		shader->use();

		cubemap.bind();

		glm::mat4 model_view_matrix = camera.get_view();

		model_view_matrix_id = shader->get_uniform_location("model_view_matrix");
		projection_matrix_id = shader->get_uniform_location("projection_matrix");

		glUniformMatrix4fv(model_view_matrix_id, 1, GL_FALSE, glm::value_ptr(model_view_matrix));
		glUniformMatrix4fv(projection_matrix_id, 1, GL_FALSE, glm::value_ptr(projection));

		glDepthMask(GL_FALSE);

		vao->bind();
		glDrawArrays(GL_TRIANGLES, 0, 36);
		vao->unbind();

		glDepthMask(GL_TRUE);

		shader->disable();
	}
}
