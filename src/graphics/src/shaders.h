#pragma once
#include "glad.h"

#include <string>
#include <vector>
#include <map>


namespace leo {

	typedef GLuint ShaderId_type;
	typedef GLuint ProgramId_type;
	typedef GLenum ShaderType_type;
	typedef GLuint ShaderDataLocation_type;

	class Shaders {
	public:
		static ShaderId_type createAndCompileShader(GLenum type, std::string src);
		static ShaderId_type createProgram(ShaderId_type vs, ShaderId_type fs);

		static std::string getDefaultVertexShader();
		static std::string getDefaultFragmentShader();

		static std::string getDefaultVertexShaderWebGL();
		static std::string getDefaultFragmentShaderWebGL();

	private:
		Shaders();
	};

	class GLShader {
	public:
		GLShader(ShaderType_type vertexOrFragment);
		~GLShader();
		ShaderId_type getId() const;
		
		void setSrc(std::string src);
		void setName(std::string name);
		
		bool compile();
		bool isCompiled();
		bool dispose();

	};
	
	class ShaderProgram {
	public:
		ShaderProgram(GLShader vs, GLShader fs);
		~ShaderProgram();

		ProgramId_type getId();
		void setName(std::string name);
		bool link();
		bool isLinked();
		bool use(bool useProgram);
		bool dispose();


	};

	class ShaderState {
		std::map<std::string, ShaderProgram>* map;

		ShaderState();
		~ShaderState();

		void addProgram(ShaderProgram program);
		void removeProgram(std::string name);

		bool useProgram(ShaderProgram program);
		bool useProgram(std::string name);

		void clear();

	};

}

