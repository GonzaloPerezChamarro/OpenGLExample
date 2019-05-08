

#ifndef SHADER_HEADER
#define SHADER_HEADER

#include <string>

#include "OpenGL.hpp"

namespace example
{
	class Shader
	{
	public:
		class Source_Code
		{
		private:
			std::string string;

		public:
			static Source_Code from_string(const std::string & code_string)
			{
				return (Source_Code(code_string));
			}

			static Source_Code from_file(const std::string & file_path);

		private:

			Source_Code() {}

			Source_Code(const std::string & source_code_string)
				:string(source_code_string)
			{}


		public:

			size_t size() const { return (string.size()); }
			bool   is_empty() const { return (string.empty()); }
			bool   is_not_empty() const { return (!string.empty()); }

		public:

			operator const std::string & () const
			{
				return (Source_Code::string);
			}

			operator const char * () const
			{
				return (Source_Code::string.c_str());
			}


		};

	private:

		GLuint      id;
		std::string log_string;

	protected:

		Shader(const Source_Code & source_code, GLenum shader_type);

		virtual ~Shader();

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

	};
}

#endif
