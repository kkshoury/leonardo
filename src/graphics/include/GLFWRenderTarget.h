#pragma once
#include "GLRenderTarget.h"
#include "glfw3.h"

namespace leo {

	class GLFWRenderTarget : public leo::GLRenderTarget {
	public:
		GLFWRenderTarget();
		~GLFWRenderTarget();

		virtual leo::GLContext* getGLContext() override;
		virtual void setOpenGLMajorMinorVersion(int major, int minor) override;
		
		virtual void setId(const std::string& id) override;
		virtual void setDim(int width, int height) override;
		virtual int getWidth() const override;
		virtual int getHeight() const override;
		virtual bool init() override;
		virtual void show() override;
		virtual void hide() override;
		virtual void terminate() override;
		virtual void swapBuffers() override;
		virtual void refresh() override;
		virtual bool shouldTerminate() const override;
		virtual void setTitle(const std::string& title) override;

		GLFWwindow* getGLFWWindow() const;

	private:
		std::string id;
		std::string title;
		int width, height;
		bool visible, windowCreated;
		int major, minor;
		static int glfwInstances;
		bool glfwInitialized = false;
		GLFWwindow *window;
	};
}