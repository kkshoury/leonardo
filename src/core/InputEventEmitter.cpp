#include "graphics.h"
#include "InputEventEmitter.h"

leo::InputEventEmitter::InputEventEmitter() 
{
	_keyListeners = std::vector<KeyEventListener*>();
	_mouseListeners = std::vector<MouseEventListener*>();
}

leo::InputEventEmitter::~InputEventEmitter()
{

}

void leo::InputEventEmitter::pollEvents() const
{
	glfwPollEvents();
}

void leo::InputEventEmitter::waitForEvents() const
{
	glfwWaitEvents();
}

void leo::InputEventEmitter::waitForEventsTimeout(double ms) const
{
	glfwWaitEventsTimeout(ms);
}

void leo::InputEventEmitter::addKeyListener(KeyEventListener* listener, InputEventEmitter::InputEventType type)
{
	_keyListeners.push_back(listener);
}

void leo::InputEventEmitter::addMouseListener(MouseEventListener* listener, InputEventEmitter::InputEventType type)
{
	_mouseListeners.push_back(listener);
}


void leo::InputEventEmitter::preInit()
{
	bool result = glfwInit();
	if (!result) {
		std::cout << "Error: failed to init GLFW on InputEventEmitter::preInit()"<<std::endl;
	}
}

void leo::InputEventEmitter::_emitKeyEvent(GLFWwindow* w, int key, int scancode, int action, int mods) 
{
	for (auto itr = std::begin(_keyListeners); itr != std::end(_keyListeners); itr++) {
		(*itr)->onKeyDown(key, 0);

	}
}

void leo::InputEventEmitter::_emitMouseButtonEvent(GLFWwindow * w, int button, int action, int mod)
{
	MouseEventListener::MouseButton_enum button_type;
	if (button == GLFW_MOUSE_BUTTON_LEFT) {
		button_type = MouseEventListener::MOUSE_BUTTON_LEFT;
	}
	else if (button == GLFW_MOUSE_BUTTON_MIDDLE) {
		button_type = MouseEventListener::MOUSE_BUTTON_MIDDLE;
	}
	else if (button == GLFW_MOUSE_BUTTON_RIGHT) {
		button_type = MouseEventListener::MOUSE_BUTTON_RIGHT;
	}
	else {
		return;
	}

	if (action == GLFW_RELEASE) {
		for (auto itr = std::begin(_mouseListeners); itr != std::end(_mouseListeners); itr++) {
			(*itr)->onMouseUp(0, 0, button_type, 0);
		}
	}
	else if (action == GLFW_PRESS) {
		for (auto itr = std::begin(_mouseListeners); itr != std::end(_mouseListeners); itr++) {
			(*itr)->onMouseDown(0, 0, button_type, 0);
		}
	}
}

void leo::InputEventEmitter::_emitMouseMoveEvent(GLFWwindow * w, double xpos, double ypos_inverse)
{
	for (auto itr = std::begin(_mouseListeners); itr != std::end(_mouseListeners); itr++) {
		(*itr)->onMouseDragged(xpos, ypos_inverse, 0);
	}
}

namespace leo {
	void glfwFoo(GLFWwindow* w, int key, int scancode, int action, int mods)
	{
		leo::InputEventEmitter* emitter = static_cast<leo::InputEventEmitter*> (glfwGetWindowUserPointer(w));
	
		emitter->_emitKeyEvent(w, key, scancode, action, mods);
	}

	void glfwMouseButtonCallback(GLFWwindow* w, int leftOrRight, int pressOrRelease, int bit) {
		leo::InputEventEmitter* emitter = static_cast<leo::InputEventEmitter*> (glfwGetWindowUserPointer(w));
		emitter->_emitMouseButtonEvent(w, leftOrRight, pressOrRelease, bit);
	}

	void glfwMouseMoveCallback(GLFWwindow* w, double x, double inverseY) {
		leo::InputEventEmitter* emitter = static_cast<leo::InputEventEmitter*> (glfwGetWindowUserPointer(w));
		emitter->_emitMouseMoveEvent(w, x, inverseY);
	}
}


void leo::InputEventEmitter::init(const AppFrameworkContext& context)
{
	window = static_cast<GLFWRenderTarget*>(context.renderTarget)->getGLFWWindow();
	if (window == nullptr) {
		std::cout << "Error: null pointer window in InputEventEmitter" << std::endl;
	}
}

void leo::InputEventEmitter::postInit()
{
	glfwSetWindowUserPointer(window, this);
	glfwSetKeyCallback(window, glfwFoo);
	glfwSetMouseButtonCallback(window, glfwMouseButtonCallback);
	glfwSetCursorPosCallback(window, glfwMouseMoveCallback);

}

void leo::InputEventEmitter::start()
{

}

void leo::InputEventEmitter::end()
{
}

void leo::InputEventEmitter::dispose()
{
	_keyListeners.clear();
	_mouseListeners.clear();
}
