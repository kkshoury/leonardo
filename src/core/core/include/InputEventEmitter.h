#pragma once

#include<iostream>
#include <memory>
#include <vector>

#include "AppFrameworkObject.h"
#include "AppFrameworkContext.h"
#include "KeyEventListener.h"
#include "MouseEventListener.h"
#include "GLFWEventEmitter.h"

namespace leo {

	class InputEventEmitter : public AppFrameworkObject {
	public:
		enum class InputEventType {DOWN, UP, CLICK, MOVE};

		InputEventEmitter();
		~InputEventEmitter();

		void pollEvents() const;
		void waitForEvents() const;
		void waitForEventsTimeout(double ms) const;

		void addKeyListener(KeyEventListener* listener, InputEventType type);
		void addMouseListener(MouseEventListener* listener, InputEventType type);

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
		std::vector<KeyEventListener*> _keyListeners;
		std::vector<MouseEventListener*> _mouseListeners;
		GLFWwindow* window;

		void _emitKeyEvent(GLFWwindow* w, int key, int scancode, int action, int mods);
		void _emitMouseButtonEvent(GLFWwindow* w, int, int , int);
		void _emitMouseMoveEvent(GLFWwindow* w, double, double);

	};


}