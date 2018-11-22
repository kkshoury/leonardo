#pragma once


#include <string>

namespace leo {

	class GLContext
	{
	public:
		virtual void setMajorMinorVersion(int major, int minor) = 0;
		virtual void setActiveGLContext() =0;

	};
}

