
#include "VertexArrayObject.h"

#include <assert.h>

namespace example
{
	Vertex_Array_Object::Vertex_Array_Object
	(
		const std::initializer_list< Vertex_Attribute_Information > & vertex_attribute_information_list,
		const std::shared_ptr< Vertex_Buffer_Object > & indices_vbo
	)
	{
		glGenVertexArrays(1, &id);

		bind();

		for (const auto & vertex_attribute_information : vertex_attribute_information_list)
		{
			vertex_attribute_information.vbo->bind();

			glEnableVertexAttribArray(vertex_attribute_information.attribute_location);

			glVertexAttribPointer
			(
				vertex_attribute_information.attribute_location,
				vertex_attribute_information.components_count,
				vertex_attribute_information.component_type,
				GL_FALSE,
				0,
				0
			);

			vbo_list.push_back(vertex_attribute_information.vbo);
		}

		if (indices_vbo.get())
		{
			indices_vbo->bind();
		}

		vbo_list.push_back(indices_vbo);

		unbind();

		error = glGetError();

		assert(error == GL_NO_ERROR);
	}
}
