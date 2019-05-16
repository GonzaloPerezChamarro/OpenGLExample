
#include "Plane.hpp"

#include <iostream>
#include <vector>

namespace example
{
	Plane::Plane(size_t width, size_t height)
		:dim(width * height)
	{
		

		vertex.resize(dim *3);
		normals.resize(dim *3);
		texcoord.resize(dim *2);
		indices.resize(2 * (width-1) * (height-1) * 3);

		//Vertex y normals
		size_t index = 0;
		for (size_t i = 0; i < height; ++i)
		{
			for (size_t j = 0; j < width; ++j,index+=3)
			{
				vertex[index] = j;
				vertex[index + 1] = 0.f;
				vertex[index + 2] = i;

				normals[index] = 0.f;
				normals[index+1] = 1.f;
				normals[index+2] = 0.f;

			}
		}
		//Texcoord
		index = 0;
		for (size_t i = 0; i < height; ++i)
		{
			for (size_t j = 0; j < width; ++j,index+=2)
			{
				texcoord[index] = j / float((width - 1));
				texcoord[index + 1] = i / float((height - 1));
			}
		}
		//Index
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
			++k;
		}

		vao.reset(new Vertex_Array_Object);
		vao->bind();

		vertex_buffer.reset(new Vertex_Buffer_Object(&vertex[0], vertex.size() * sizeof(GLfloat)));
		//vertex_buffer.reset(new Vertex_Buffer_Object(&vertex[0], sizeof(vertex)));
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, vertex_buffer->get_element_type(), GL_FALSE, 3 * sizeof(GLfloat), 0);
		
		//texcoord_buffer.reset(new Vertex_Buffer_Object(&texcoord[0], sizeof(texcoord)));
		texcoord_buffer.reset(new Vertex_Buffer_Object(&texcoord[0],texcoord.size() * sizeof(texcoord)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, texcoord_buffer->get_element_type(), GL_FALSE, 2 * sizeof(GLfloat), 0);

		//normals_buffer.reset(new Vertex_Buffer_Object(&normals[0], sizeof(normals)));
		normals_buffer.reset(new Vertex_Buffer_Object(&normals[0], normals.size() * sizeof(GLfloat)));
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 3, normals_buffer->get_element_type(), GL_FALSE, 3 * sizeof(GLfloat), 0);

		//indices_buffer.reset(new Vertex_Buffer_Object(&indices[0], sizeof(indices), Vertex_Buffer_Object::EAB));
		indices_buffer.reset(new Vertex_Buffer_Object(&indices[0], indices.size() * sizeof(GLubyte), Vertex_Buffer_Object::EAB));

		vao->unbind();

	
	}

	void Plane::render()
	{
		vao->bind();
		//glDrawElements(GL_TRIANGLES,sizeof(indices), GL_UNSIGNED_BYTE, 0);
		glDrawElements(GL_TRIANGLES,GLsizei(sizeof(std::vector<GLubyte>) * indices.size()), GL_UNSIGNED_BYTE, 0);
	}
}