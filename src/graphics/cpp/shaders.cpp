#include <iostream>
#include "shaders.h"
#include "glfw3.h"

GLuint leo::Shaders::createAndCompileShader(GLenum type, std::string src) {

	GLuint shader = glCreateShader(type);
	const char* cstr = src.c_str();
	const GLchar* const * pSrc = &cstr;

	int x = src.length();
	GLint* size = &x;

	glShaderSource(shader, 1, pSrc, size);
	;	if (0 == shader) {
		return 0;
	}

	glCompileShader(shader);

	int infoLen = 0;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
	if (infoLen > 1) {
		char* infoLog = new char[infoLen];

		// And print them out
		glGetShaderInfoLog(shader, infoLen, NULL, infoLog);
		printf("%s\n", infoLog);

		delete infoLog;
		return 0;
	}

	return shader;
}

GLuint leo::Shaders::createProgram(GLuint vs, GLuint fs) {

	if (vs == 0 || fs == 0) {
		return 0;
	}

	GLuint program = 0;
	program = glCreateProgram();
	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glLinkProgram(program);
	glValidateProgram(program);

	int  success;
	char infoLog[512];
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;

	}

	return program;
}


std::string leo::Shaders::getDefaultVertexShader() {
	return
		"#version 430 core \n"
		"layout (location = 0) in vec3 position;     \n"
		"void main()                  \n"
		"{                            \n"
		"   gl_Position = vec4(position, 1.0);   \n"
		"}                            \n";
}
std::string leo::Shaders::getDefaultFragmentShader() {
	return
		"#version 430 core \n"
		"out vec4 FragColor;                            \n"
		"void main()                                         \n"
		"{                                                   \n"
		"  FragColor = vec4(1.0, 0.0, 0.0, 1.0);			 \n"
		"}                                                   \n";

}

std::string leo::Shaders::getDefaultVertexShaderWebGL() {
	return
		"attribute vec3 position;     \n"
		"attribute vec3 color;		  \n"
		"varying vec3 var_color; \n"
		"void main()                  \n"
		"{                            \n"
		"   gl_Position = vec4(position, 1.0);   \n"
		"var_color = color; \n"

		"}                            \n";
}
std::string leo::Shaders::getDefaultFragmentShaderWebGL() {
	return
		"precision mediump float;                            \n"
		"varying vec3 var_color;"
		"void main()                                         \n"
		"{                                                   \n"
		"  gl_FragColor = vec4(var_color, 1.0);			 \n"
		"}                                                   \n";

}