

#include "Cube.h"


namespace example
{
	const GLfloat Cube::vertex[] =
	{
		// front
		-1.f, -1.f,  1.f,
		 1.f, -1.f,  1.f,
		 1.f,  1.f,  1.f,
		-1.f,  1.f,  1.f,

		// right
		 1.f, -1.f,  1.f,
		 1.f, -1.f, -1.f,
		 1.f,  1.f, -1.f,
		 1.f,  1.f,  1.f,

		 // back 
		  1.f, -1.f, -1.f,
		 -1.f, -1.f, -1.f,
		 -1.f,  1.f, -1.f,
		  1.f,  1.f, -1.f,

		  // left
		  -1.f, -1.f, -1.f,
		  -1.f, -1.f,  1.f,
		  -1.f,  1.f,  1.f,
		  -1.f,  1.f, -1.f,

		  // top
		  -1.f,  1.f,  1.f,
		   1.f,  1.f,  1.f,
		   1.f,  1.f, -1.f,
		  -1.f,  1.f, -1.f,

		  // bottom
		   1.f, -1.f,  1.f,
		  -1.f, -1.f,  1.f,
		  -1.f, -1.f, -1.f,
		   1.f, -1.f, -1.f
	};

	const GLfloat Cube::texcoord[] =
	{
		// front
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,

		// right 
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,

		// back 
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,

		// left 
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,

		// top
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,

		// bottom
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,
	};

	const GLfloat Cube::normals[] = 
	{
		// front
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,

		// right
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,

		// back
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,

		// left
		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,

		// top 
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,

		// bottom 
		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
	};

	const GLubyte Cube::indices[] =
	{
		// front
		0, 1, 3,
		1, 2, 3,

		// right
		4, 5, 7,
		5, 6, 7,

		// back
		8,  9, 11,
		9, 10, 11,

		// left
		12, 13, 15,
		13, 14, 15,

		// top
		16, 17, 19,
		17, 18, 19,

		// bottom 
		20, 21, 23,
		21, 22, 23
	};

	Cube::Cube()
	{
		vao.reset(new Vertex_Array_Object);

		vao->bind();

		vertex_buffer.reset(new Vertex_Buffer_Object(vertex, sizeof(vertex)));
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, vertex_buffer->get_element_type(), GL_FALSE, 3 * sizeof(GLfloat), 0);

		texcoord_buffer.reset(new Vertex_Buffer_Object(texcoord, sizeof(texcoord)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, texcoord_buffer->get_element_type(), GL_FALSE, 2 * sizeof(GLfloat), 0);

		normals_buffer.reset(new Vertex_Buffer_Object(normals, sizeof(normals)));
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 3, normals_buffer->get_element_type(), GL_FALSE, 3 * sizeof(GLfloat), 0);

		indices_buffer.reset(new Vertex_Buffer_Object(indices, sizeof(indices), Vertex_Buffer_Object::Target::EAB));

		vao->unbind();

	}

	void Cube::render()
	{
		vao->bind();
		glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_BYTE, 0);
	}
}
