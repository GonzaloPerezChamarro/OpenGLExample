#ifndef TEXTURE_HEADER
#define TEXTURE_HEADER

#include "OpenGL.hpp"
#include "SFML/Graphics.hpp"

#include <string>
#include <vector>

namespace example
{
	class Texture
	{
	public:
		enum Parameter {
			REPEAT = GL_REPEAT,
			MIRRORED = GL_MIRRORED_REPEAT,
			CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
			CLAMP_TO_BORDER = GL_CLAMP_TO_BORDER,

			NEAREST = GL_NEAREST,
			LINEAR = GL_LINEAR,
			MIPMAP_NEAREST = GL_LINEAR_MIPMAP_NEAREST,
			MIPMAP_LINEAR = GL_LINEAR_MIPMAP_LINEAR
		};


	protected:

		GLenum id;
		GLenum error;

		bool success;

		std::vector <sf::Color> texture_buffer;

	public:
		Texture() = default;

		virtual ~Texture();

	public:

		virtual void load_texture(const std::string & path) = 0;

		virtual void bind() = 0;

		virtual void unbind() = 0;

		virtual void set_wrap(Parameter) {};

		virtual void set_filter(Parameter) {};

		bool is_ready() { return success; }

		size_t get_size() { texture_buffer.size(); }

	};
}
#endif
