#pragma once
#include "GLContext.h"

namespace leo {


	class GLFWGLContext : public leo::IGLContext
	{
	public:
		GLFWGLContext() {}
		~GLFWGLContext() {}

		// Inherited via GLContext
		virtual void setMajorMinorVersion(int major, int minor) override;
	};
}
