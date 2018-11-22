#pragma once

#include<iostream>
#include <memory>
#include <vector>

#include "AppFrameworkObject.h"
#include "AppFrameworkContext.h"
#include "KeyEventListener.h"
#include "MouseEventListener.h"
#include "GLFWEventEmitter.h"
#include "glfw3.h"

namespace leo {

	class InputEventEmitter : public AppFrameworkObject {
	public:
		const static int INPUT_EVENT_KEY_DOWN = 0;
		const static int INPUT_EVENT_KEY_UP = 1;
		const static int INPUT_EVENT_KEY_CLICK = 2;
		const static int INPUT_EVENT_KEY_DOUBLE_CLICK = 3;

		InputEventEmitter();
		~InputEventEmitter();

		void pollEvents() const;
		void waitForEvents() const;
		void waitForEventsTimeout(double ms) const;

		void addKeyListener(std::shared_ptr<KeyEventListener> listener, int even_type);
		void addMouseListener(std::shared_ptr<MouseEventListener> listener, int event_type);

		// Inherited via AppFrameworkObject
		virtual void preInit() override;

		virtual void init(const AppFrameworkContext& context) override;

		virtual void postInit() override;

		virtual void start() override;

		virtual void end() override;

		virtual void dispose() override;

		friend void glfwFoo(GLFWwindow* w, int key, int scancode, int action, int mods);
		friend void glfwMouseButtonCallback(GLFWwindow* window, int leftOrRight, int pressOrRelease, int bit);
		friend void glfwMouseMoveCallback(GLFWwindow* window, double x, double inverseY);

	private:
		std::vector<std::shared_ptr<KeyEventListener>> _keyListeners;
		std::vector<std::shared_ptr<MouseEventListener>> _mouseListeners;
		GLFWwindow* window;

		void _emitKeyEvent(GLFWwindow* w, int key, int scancode, int action, int mods);
		void _emitMouseButtonEvent(GLFWwindow* w, int, int , int);
		void _emitMouseMoveEvent(GLFWwindow* w, double, double);

	};


}