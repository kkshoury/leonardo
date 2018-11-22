#pragma once
#include "glad.h"

#include <string>


class Shaders {
public:
	static GLuint compileShader(GLenum type, std::string src);
	static GLuint createProgram(GLuint, GLuint);

	static std::string getDefaultVertexShader();
	static std::string getDefaultFragmentShader();

	static std::string getDefaultVertexShaderWebGL();
	static std::string getDefaultFragmentShaderWebGL();

private:
	Shaders();
};