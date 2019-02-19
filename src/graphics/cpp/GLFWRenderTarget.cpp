#include "GLFWRenderTarget.h"
#include "GLContext.h"
#include "glfw3.h"

int leo::GLFWRenderTarget::glfwInstances = 0;

void leo::GLFWRenderTarget::setId(const std::string& id) {
	this->id = id;
}

leo::GLFWRenderTarget::GLFWRenderTarget() {
	width = 800;
	height = 800;
	glfwInstances++;
	title = "GLFW Instance " + glfwInstances;
	if (!glfwInitialized) {
		glfwInitialized = (glfwInit() == GLFW_TRUE);
	}
}

leo::GLFWRenderTarget::~GLFWRenderTarget() {
	glfwInstances--;
	if (glfwInstances == 0) {
		glfwTerminate();
	}
	window = nullptr;
}

void leo::GLFWRenderTarget::setDim(int width, int height)
{
	if(width > 0) this->width = width;
	if(height > 0) this->height = height;

}

int leo::GLFWRenderTarget::getWidth()  const { return width; }

int leo::GLFWRenderTarget::getHeight() const { return height; }

bool leo::GLFWRenderTarget::init()
{
	if (!windowCreated && glfwInitialized) {

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


		this->window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		
		if (!window) {
			return false;
		}

		glfwMakeContextCurrent(window);
		windowCreated = true;
		return true;
	}

	return false;

}

void leo::GLFWRenderTarget::show()
{
	init();
	glfwShowWindow(this->window);
}

void leo::GLFWRenderTarget::hide()
{
	init();
	glfwHideWindow(this->window);
}

void leo::GLFWRenderTarget::terminate()
{
	if (windowCreated) {
		glfwDestroyWindow(window);
	}
	windowCreated = false;
}

void leo::GLFWRenderTarget::swapBuffers()
{
	if (windowCreated) {
		glfwSwapBuffers(window);
	}
}

void leo::GLFWRenderTarget::refresh()
{

}

void leo::GLFWRenderTarget::setTitle(const std::string& title) 
{
	this->title = title;
}

GLFWwindow * leo::GLFWRenderTarget::getGLFWWindow() const
{
	return window;
}

bool leo::GLFWRenderTarget::shouldTerminate() const
{
	return glfwWindowShouldClose(window);
}

void leo::GLFWRenderTarget::setOpenGLMajorMinorVersion(int major, int minor)
{
	this->major = major;
	this->minor = minor;
}

leo::IGLContext* leo::GLFWRenderTarget::getGLContext() {
	return nullptr;
}

