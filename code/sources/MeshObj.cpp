


#include "MeshObj.hpp"

#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>
#include <vector>
#include <string>
#include <iostream>

using namespace tinyobj;

namespace example
{
	Mesh_Obj::Mesh_Obj(const std::string & file)
	{
		//Carga del .obj
		load_obj(file);

		//Vao y vbos
		vao.reset(new Vertex_Array_Object);
		vao->bind();

		vertex_buffer.reset(new Vertex_Buffer_Object(&vertex[0], vertex.size() * sizeof(GLfloat)));
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, vertex_buffer->get_element_type(), GL_FALSE, 3 * sizeof(GLfloat), 0);

		if (texcoord.size() > 0)
		{
			texcoord_buffer.reset(new Vertex_Buffer_Object(&texcoord[0], texcoord.size() * sizeof(GLfloat)));
			glEnableVertexAttribArray(2);
			glVertexAttribPointer(2, 2, texcoord_buffer->get_element_type(), GL_FALSE, 2 * sizeof(GLfloat), 0);
		}

		normals_buffer.reset(new Vertex_Buffer_Object(&normals[0], normals.size() * sizeof(GLfloat)));
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 3, normals_buffer->get_element_type(), GL_FALSE, 3 * sizeof(GLfloat), 0);

		indices_buffer.reset(new Vertex_Buffer_Object(&indices[0], indices.size() * sizeof(GLubyte), Vertex_Buffer_Object::EAB));

		vao->unbind();
	}

	void Mesh_Obj::render()
	{
		vao->bind();
		glDrawElements(GL_TRIANGLES, GLsizei(sizeof(GLubyte) * indices.size()), GL_UNSIGNED_BYTE, 0);
	}

	void Mesh_Obj::load_obj(const std::string & file)
	{
		std::vector<shape_t> shapes;
		std::vector<material_t> materials;

		attrib_t attributes;

		
		if (!LoadObj(&attributes, &shapes, &materials, &log_error, file.c_str(),0, true))
		{
			assert(false);
			return;
		}

		//Comprobacion de errores
		if (attributes.vertices.size() == 0) { log_error += std::string("vertex error"); }
		if (attributes.normals.size() == 0) { log_error += std::string("normals error"); }
		if (attributes.texcoords.size() == 0) { log_error += std::string("Texcoord error"); }
		if (shapes.size() == 0) { log_error = std::string("Shapes Error"); }

		std::cout << log_error << std::endl;
				
		vertex = attributes.vertices;
		texcoord = attributes.texcoords;
		
		normals = attributes.normals;
		indices.resize(shapes[0].mesh.indices.size());

		for (size_t i = 0; i < indices.size(); ++i)
		{
			indices[i] = shapes[0].mesh.indices[i].vertex_index ;
		}

	}

}