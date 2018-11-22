#pragma once
#include "GLContext.h"

namespace leo {


	class GLFWGLContext : public leo::GLContext
	{
	public:
		GLFWGLContext() {}
		~GLFWGLContext() {}

		// Inherited via GLContext
		virtual void setMajorMinorVersion(int major, int minor) override;

		virtual void setActiveGLContext() override;

	};
}
