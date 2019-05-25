

#include "ElevationMesh.hpp"

#include "Color_Rgba8888.hpp"
#include <assert.h>

#include <iostream>

extern "C"
{
#include <targa.h>
}

namespace example
{
	Elevation_Mesh::Elevation_Mesh(const std::string & path_file,unsigned width, unsigned height)
	{
		//LOAD IMAGE
		tga_image image;

		std::vector<Color_RGBA8888> colors;

		if (tga_read(&image, path_file.c_str()) == TGA_NOERR)
		{
			colors.resize(image.width * image.height);
			tga_convert_depth(&image, sizeof(Color_RGBA8888) * 8);

			Color_RGBA8888 * begin = reinterpret_cast<Color_RGBA8888*>(image.image_data);
			Color_RGBA8888 * end = begin + image.width * image.height;
			Color_RGBA8888 * buffer = &colors.front();

			while (begin < end)
				*buffer++ = *begin++;

		}
		else
			assert(false);

		//! load image

		//GENERATE VERTEX
		vertex.resize(width * height * 3);
		normals.resize(width * height * 3);
		texcoord.resize(width * height * 2);
		indices.resize(2 * (width - 1) * (height - 1) * 3);

		float elevation = 0;
		float increment = image.width / float(width);

		size_t index = 0;
		for (size_t i = 0; i < height; ++i)
		{
			for (size_t j = 0; j < width; ++j, index += 3, elevation += increment)
			{
				vertex[index] = j;
				vertex[index + 1] = (colors[size_t(elevation)].data.component.r / float(255)) * 10.f;
				vertex[index + 2] = i;
			}
		}

		index = 0;
		for (size_t i = 0; i < height; ++i)
		{
			for (size_t j = 0; j < width; ++j, index += 2)
			{
				texcoord[index] = j / float((width - 1));
				texcoord[index + 1] = i / float((height - 1));
			}
		}

		//! generate vertex

		// GENERATE NORMALS
		index = 0;
		for (size_t i = 0; i < height; ++i)
		{
			for (size_t j = 0; j < width; ++j, index += 3)
			{
				glm::vec3 n = calculate_normal(width, height, i, index / 3);
				normals[index] = n[0];
				normals[index + 1] = n[1];
				normals[index + 2] = n[2];
				//normals[index] = 0.f;
				//normals[index + 1] = 1;
				//normals[index + 2] = 0;
				std::cout <<"Height: " << i << ", Width: " << j << std::endl;
				
			}
		}

		//! generate normals
		//GENERATE INDICES

		index = 0;
		for (size_t i = 0, k = 0; i < height - 1; ++i)
		{
			for (size_t j = 0; j < width - 1; ++j, ++k, index += 6)
			{
				indices[index] = k;
				indices[index + 1] = k + width;
				indices[index + 2] = k + 1;

				indices[index + 3] = k + 1;
				indices[index + 4] = k + width;
				indices[index + 5] = k + 1 + width;
			}
			++k;
		}

		tga_free_buffers(&image);

		//VAO y VBOs

		vao.reset(new Vertex_Array_Object);
		vao->bind();

		vertex_buffer.reset(new Vertex_Buffer_Object(&vertex[0], vertex.size() * sizeof(GLfloat)));
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, vertex_buffer->get_element_type(), GL_FALSE, 3 * sizeof(GLfloat), 0);

		texcoord_buffer.reset(new Vertex_Buffer_Object(&texcoord[0], sizeof(texcoord)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, texcoord_buffer->get_element_type(), GL_FALSE, 2 * sizeof(GLfloat), 0);

		normals_buffer.reset(new Vertex_Buffer_Object(&normals[0], normals.size() * sizeof(GLfloat)));
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 3, normals_buffer->get_element_type(), GL_FALSE, 3 * sizeof(GLfloat), 0);

		indices_buffer.reset(new Vertex_Buffer_Object(&indices[0], indices.size() * sizeof(GLuint), Vertex_Buffer_Object::EAB));

		vao->unbind();


	}

	void Elevation_Mesh::render()
	{
		vao->bind();
		glDrawElements(GL_TRIANGLES, GLsizei(sizeof(indices) * indices.size()), GL_UNSIGNED_INT, 0);
	}

	glm::vec3 Elevation_Mesh::calculate_normal(unsigned width, unsigned height, size_t i, size_t index)
	{
		glm::vec3 result = glm::vec3();
		std::vector<glm::vec3> near_points;
		std::vector<glm::vec3> vertices = convert_vec1_to_vec3(vertex);

		const glm::vec3 & point = vertices[index];
		size_t vertex_count = vertex.size() / 3;

		size_t start = i * height;
		size_t end = i * height + (width - 1);

		//Calculo de excepciones
		//1
		int temp = index - width;
		if (temp > 0)
		{
			glm::vec3 aux = vertices[index - width];
			glm::vec3 new_point = aux - point;
			near_points.push_back(glm::normalize(new_point));
		}
		//2
		if (index - 1 > 0)
		{
			if (index > start && index < end)
			{
				glm::vec3 aux = vertices[index - 1];
				glm::vec3 new_point = aux - point;
				near_points.push_back(glm::normalize(new_point));
			}
		}
		//3
		if ((index + width - 1) > 0 && (index + width - 1 < vertex_count - 1))
		{
			if (!(index > start && index < end))
			{
				glm::vec3 aux = vertices[(index + width) - 1];
				glm::vec3 new_point = aux - point;
				near_points.push_back(glm::normalize(new_point));
			}
		}
		//4
		if (index + width > 0 && index + width < vertex_count - 1)
		{
			glm::vec3 aux = vertices[index + width];
			glm::vec3 new_point = aux - point;
			near_points.push_back(glm::normalize(new_point));
		}
		//5
		if (index + 1 > 0 && index + 1 < vertex_count - 1)
		{
			if (index > start && index < end)
			{
				glm::vec3 aux = vertices[index+1];
				glm::vec3 new_point = aux - point;
				near_points.push_back(glm::normalize(new_point));
			}
		}
		//6
		temp = index - width + 1;
		if (temp > 0)
		{
			if (!(index > start && index < end))
			{
				glm::vec3 aux = vertices[index - width +1];
				glm::vec3 new_point = aux - point;
				near_points.push_back(glm::normalize(new_point));
			}
		}

		//------------------------------------------------

		std::vector<glm::vec3> products;

		for (size_t j = 0; j < near_points.size() - 1; ++j)
		{
			glm::vec3 & vec1 = near_points[j];
			glm::vec3 & vec2 = near_points[j+1];

			products.push_back(glm::cross(vec1, vec2));
		}

		if (near_points.size() > 1)
		{
			glm::vec3 & begin = near_points[0];
			glm::vec3 & end = near_points[near_points.size() - 1];

			products.push_back(glm::cross(begin, end));
		}

		//Calcular medias entre puntos

		for (size_t k = 0; k < products.size(); ++k)
		{
			result += products[k];
		}

		result /= products.size();

		return glm::normalize(result);

	}

	std::vector<glm::vec3> Elevation_Mesh::convert_vec1_to_vec3(std::vector<float>& vector1)
	{
		bool check = vector1.size() % 3 == 0;
		assert(check);

		std::vector<glm::vec3> result;
		result.resize(vector1.size() / 3);

		for (size_t i = 0, j = 0; i < result.size(); ++i, j+=3)
		{
			result[i] = { vector1[j],vector1[j+1] ,vector1[j+2] };
		}

		return result;
	}
}