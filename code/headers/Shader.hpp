/**
 * @file Shader.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Base class of a shader
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef SHADER_HEADER
#define SHADER_HEADER

#include <string>

#include "OpenGL.hpp"

namespace example
{
	class Shader
	{
	public:
		/* Class of a shader code */
		class Source_Code
		{

		public:
			/* Returns a Source_Code object from a code string */
			static Source_Code from_string(const std::string & code_string)
			{
				return (Source_Code(code_string));
			}

			/* Returns a Source_Code object from a file */
			static Source_Code from_file(const std::string & file_path);

		public:
			size_t size() const { return (string.size()); }
			bool   is_empty() const { return (string.empty()); }
			bool   is_not_empty() const { return (!string.empty()); }

		public:

			operator const std::string& () const
			{
				return (Source_Code::string);
			}

			operator const char* () const
			{
				return (Source_Code::string.c_str());
			}

		private:
			/* Constructor by default */
			Source_Code() {}

			/* Constructor from a source code string */
			Source_Code(const std::string & source_code_string)
				:string(source_code_string)
			{}

		private:
			/* Code*/
			std::string string;
		};

	public:
		bool is_compiled() const
		{
			return (id != 0);
		}

		bool compilation_failed() const
		{
			return (id == 0);
		}

		const std::string & log() const
		{
			return (log_string);
		}

		operator GLuint () const
		{
			return (id);
		}

	protected:
		/**
		 * @brief Constructor
		 * @param source_code Source code object
		 * @param shader_type Vertex or fragment
		 */
		Shader(const Source_Code& source_code, GLenum shader_type);

		/* Destructor */
		virtual ~Shader();

	private:
		/* Shader id */
		GLuint id;

		/* Error log */
		std::string log_string;
	};
}

#endif
