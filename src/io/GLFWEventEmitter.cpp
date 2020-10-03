#include "GLFWEventEmitter.h"


static void foo(GLFWwindow* w, int key, int scancode, int action, int mods)
{
	static_cast<leo::GLFWEventEmitter*>(glfwGetWindowUserPointer(w))->keyCallback(key, scancode, action, mods);

}

void leo::GLFWEventEmitter::init(GLFWwindow* eventSource) const 
{
	glfwInit();
	GLFWEventEmitter pointer = *this;
	glfwSetWindowUserPointer(eventSource, &pointer);
	glfwSetKeyCallback(eventSource, foo);

}

void leo::GLFWEventEmitter::pollEvents() const
{
	glfwPollEvents();
}

void leo::GLFWEventEmitter::waitForEvents() const
{
	glfwWaitEvents();
}

void leo::GLFWEventEmitter::waitForEventsTimeout(double ms) const
{
	glfwWaitEventsTimeout(ms);
}

#include <iostream>
void leo::GLFWEventEmitter::keyCallback(int key, int scancode, int action, int mods)
{
	std::cout << key << std::endl;
;
}

void leo::GLFWEventEmitter::mouseCallback()
{
}

void leo::GLFWEventEmitter::addKeyListener(std::shared_ptr<KeyEventListener> list)
{
	keyListeners.push_back(list);
}

void leo::GLFWEventEmitter::emit() const
{
	for (auto itr = std::begin(keyListeners); itr != std::end(keyListeners); itr++) {
		(*itr)->onKeyDown('M', 0.0);
	}
}


