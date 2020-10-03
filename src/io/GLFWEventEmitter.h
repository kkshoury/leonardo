#pragma once
#include <vector>
#include <memory>

#include "glfw3.h"
#include "MouseEventListener.h"
#include "KeyEventListener.h"

namespace leo {

	class GLFWEventEmitter {
	public:
		void init(GLFWwindow* eventSource) const;
		void pollEvents() const;
		void waitForEvents() const;
		void waitForEventsTimeout(double ms) const;

		void keyCallback(int key, int scancode, int action, int mods);
		void mouseCallback();

		void addKeyListener(std::shared_ptr<KeyEventListener> list);
		void emit() const;

	private:
		std::vector<std::shared_ptr<KeyEventListener>> keyListeners;
		std::vector<std::shared_ptr<MouseEventListener>> mouseListeners;

	};


}