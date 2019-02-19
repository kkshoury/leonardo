#pragma once
#include "GLContext.h"
namespace leo {
	
	class GLVertexBufferUnit {
	public:
		enum VertexBufferData {VERTICES, COLORS};
		GLVertexBufferUnit();
		~GLVertexBufferUnit();

		/*
		creates an empty vertex buffer with size = ( vertexCount * coordinatesCount ) * size_of<float>
		*/
		void create(const IGLContext& gl, unsigned int vertexCount, unsigned int coordinatesCounts);
		void dispose();





	};

	class GLVertexBufferController {
		
	};

	class GLVertexBufferObject {
	public:
		static GLVertexBufferObject createBuffer(unsigned int maxCapacity, GLenum type, int componentsCount, bool normalized, int stride);
		
		void lock();
		void unlock();
		bool isLocked();
		void dispose();
		bool buffer(void* dataToBuffer, unsigned int count);
		bool buffer(void* dataToBuffer, unsigned int destIndex, unsigned int srcStartIndex, unsigned int count);


		GLVertexBufferObject(const GLVertexBufferObject& obj) = delete;
		GLVertexBufferObject operator=(const GLVertexBufferObject& obj) = delete;

	private:
		GLVertexBufferObject();

	};
}