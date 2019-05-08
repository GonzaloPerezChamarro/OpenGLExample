

#ifndef SKYBOX_HEADER
#define SKYBOX_HEADER

#include "Camera.hpp"
#include "Cubemap.hpp"
#include "ShaderProgram.hpp"
#include "VertexArrayObject.hpp"
#include "VertexBufferObject.hpp"

namespace example
{
	class Skybox
	{
	private:
		std::shared_ptr<Vertex_Array_Object> vao;
		std::shared_ptr<Vertex_Buffer_Object> vbo;

		GLint model_view_matrix_id;
		GLint projection_matrix_id;

		Cubemap cubemap;
		std::shared_ptr<Shader_Program> shader;

	public:
		Skybox(const std::string & path);
		~Skybox();

		void render(const glm::mat4 & projection, const Camera & camera);
	};
}

#endif
