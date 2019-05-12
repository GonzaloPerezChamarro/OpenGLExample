
#include "Plane.hpp"

#include <vector>

namespace example
{
	Plane::Plane(unsigned width, unsigned height)
		:dim(width * height)
	{

		vertex.resize(dim *3);
		normals.resize(dim *3);
		texcoord.resize(dim *2);
		indices.resize(dim *3);

		size_t index = 0;
		for (size_t i = 0; i < height; ++i)
		{
			for (size_t j = 0; j < width; ++j,index+=3)
			{
				vertex[index] = j;
				vertex[index + 1] = 0.f;
				vertex[index + 2] = i;

				normals[index] = 0;
				normals[index+1] = 1;
				normals[index+2] = 0;
			}
		}

		index = 0;
		for (size_t i = 0; i < height; ++i)
		{
			for (size_t j = 0; i < width; ++j,index+=2)
			{
				texcoord[index] = j / (width - 1);
				texcoord[index + 1] = i / (height - 1);
			}
		}

		index = 0;
		for (size_t i = 0, k = 0; i < height - 1; ++i)
		{
			for (size_t j = 0; j < width - 1; ++j, ++k, index += 6)
			{
				indices[index] = k;
				indices[index+1] = k + width;
				indices[index+2] = k + 1;

				indices[index + 3] = k + 1;
				indices[index + 4] = k + width;
				indices[index + 5] = k + 1 + width;
			}
		}

		const GLfloat v[3] = vertex;
		const GLfloat t[dim] = texcoord;
		const GLfloat n[dim] = normals;
		const GLfloat i[dim] = indices;

		vao.reset(new Vertex_Array_Object);
		vao->bind();

		vertex_buffer.reset(new Vertex_Buffer_Object(v, sizeof(vertex)));
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, vertex_buffer->get_element_type(), GL_FALSE, 3 * sizeof(GLfloat), 0);
		
		texcoord_buffer.reset(new Vertex_Buffer_Object()
	
	}

	void Plane::render()
	{
	}
}