#pragma once
#include "GLContext.h"

namespace leo {


	class GLRenderTarget
	{
	public:
		virtual void setId(const std::string& id) = 0;
		virtual void setOpenGLMajorMinorVersion(int major, int minor) = 0;
		virtual leo::GLContext* getGLContext() = 0;

		virtual void setDim(int width, int height) = 0;
		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;
		virtual bool init() = 0;
		virtual void show() = 0;
		virtual void hide() = 0;
		virtual void terminate() = 0;
		virtual void swapBuffers() = 0;
		virtual void refresh() = 0;
		virtual bool shouldTerminate() const = 0;
		virtual void setTitle(const std::string& title) = 0;

	};
}