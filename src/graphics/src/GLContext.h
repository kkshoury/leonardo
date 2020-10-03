#pragma once

#ifndef __GL_CONTEXT__
#define __GL_CONTEXT__
#include <string>
#include "glad.h"

namespace leo {

	class IGLContext
	{
	public:
		virtual void setMajorMinorVersion(int major, int minor) = 0;

	};

	/**
		Core OpenGL profile API common to OpenGL 2, OpenGL ES2, and WebGL 2
	*/
	class IGLCoreProfile : public IGLContext{

	};

	class IGL2ES2 : IGLCoreProfile {
	public:
		virtual void attachShader(GLuint program, GLuint shader) = 0;
		virtual void bindAttributeLocation(GLuint program, GLuint index, const GLchar *name) = 0;
		virtual void bindBuffer(GLenum target, GLuint buffer) = 0;
		virtual void bindTexture(GLenum target, GLuint texture) = 0;
		virtual void bufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) = 0;
		virtual void bufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) = 0;
		virtual void clear(GLbitfield mask) = 0;
		virtual void clearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) = 0;
		virtual void clearDepth(GLclampd depth) = 0;

		virtual void color3b(GLbyte red, GLbyte green, GLbyte blue) = 0;
		virtual void color3s(GLshort red, GLshort green, GLshort blue) = 0;
		virtual void color3i(GLint red, GLint green, GLint blue) = 0;
		virtual void color3f(GLfloat red, GLfloat green, GLfloat blue) = 0;
		virtual void color3d(GLdouble red, GLdouble green, GLdouble blue) = 0;
		virtual void color3ub(GLubyte red, GLubyte green, GLubyte blue) = 0;
		virtual void color3us(GLushort red, GLushort green, GLushort blue) = 0;
		virtual void color3ui(GLuint red, GLuint green, GLuint blue) = 0;
		virtual void color4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) = 0;
		virtual void color4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) = 0;
		virtual void color4i(GLint red, GLint green, GLint blue, GLint alpha) = 0;
		virtual void color4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) = 0;
		virtual void color4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) = 0;
		virtual void color4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) = 0;
		virtual void color4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) = 0;
		virtual void color4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) = 0;

		virtual void compileShader(GLuint shader) = 0;
		virtual GLuint createProgram(void) = 0;
		virtual GLuint createShader(GLenum shaderType) = 0;

		virtual void deleteBuffers(GLsizei n, const GLuint * buffers) = 0;
		virtual void deleteProgram(GLuint program) = 0;
		virtual void deleteShader(GLuint shader) = 0;
		virtual void deleteTextures(GLsizei n, const GLuint * textures) = 0;
		virtual void detachShader(GLuint program, GLuint shader) = 0;
		virtual void enable(GLenum  	cap) = 0;
		virtual void disable(GLenum  	cap) = 0;
		virtual void enableVertexAttribArray(GLuint index) = 0;
		virtual void disableVertexAttribArray(GLuint index) = 0;
		virtual void drawArrays(GLenum mode, GLint first, GLsizei count) = 0;
		virtual void drawBuffer(GLenum mode) = 0;
		virtual void drawBuffers(GLsizei n, const GLenum *bufs) = 0;
		virtual void drawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices) = 0;
		virtual void drawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * data) = 0;
		virtual void drawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices) = 0;
		virtual void genBuffers(GLsizei n, GLuint * buffers) = 0;
		virtual GLint getAttribLocation(GLuint program, const GLchar *name) = 0;
		virtual GLint getUniformLocation(GLuint program, const GLchar *name) = 0;
		virtual void getVertexAttribdv(GLuint index, GLenum pname, GLdouble *params) = 0;
		virtual void getVertexAttribfv(GLuint index, GLenum pname, GLfloat *params) = 0;
		virtual void getVertexAttribiv(GLuint index, GLenum pname, GLint *params) = 0;
		virtual void getVertexAttribPointerv(GLuint index, GLenum pname, GLvoid **pointer) = 0;
		virtual void lineWidth(GLfloat width) = 0;
		virtual void linkProgram(GLuint program) = 0;
		virtual void polygonOffset(GLfloat factor, GLfloat units) = 0;
		virtual void readPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * data) = 0;

		virtual void uniform1f(GLint location, GLfloat v0) = 0;
		virtual void uniform2f(GLint location, GLfloat v0, GLfloat v1) = 0;
		virtual void uniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) = 0;
		virtual void uniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) = 0;
		virtual void uniform1i(GLint location, GLint v0) = 0;
		virtual void uniform2i(GLint location, GLint v0, GLint v1) = 0;
		virtual void uniform3i(GLint location, GLint v0, GLint v1, GLint v2) = 0;
		virtual void uniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) = 0;

		virtual void useProgram(GLuint program) = 0;
		virtual void vertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer) = 0;
	};
}
#endif