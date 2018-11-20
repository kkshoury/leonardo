#include "../include/app.h"


void leo::App::preInit() {
	//initLibraries
	//configuration
	appObjects = getAppObjects();

	for (auto itr = std::begin(*appObjects); itr != std::end(*appObjects); itr++) {
		(*itr)->preInit();
	}
}

void leo::App::init() {
	//initialize main components of application
	window = new GLFWRenderTarget();
	eventEmitter = new GLFWEventEmitter();

	for (auto itr = std::begin(*appObjects); itr != std::end(*appObjects); itr++) {
		(*itr)->init();
	}
}

void leo::App::postInit() {
	//set listeners
	//initial setup

	window->setTitle("Leonardo");
	window->setDim(800, 600);
	window->setOpenGLMajorMinorVersion(4, 3);
	window->init();
	eventEmitter->init(((GLFWRenderTarget*) window)->getGLFWWindow());


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		return;
	}

	for (auto itr = std::begin(*appObjects); itr != std::end(*appObjects); itr++) {
		(*itr)->postInit();
	}
}

void leo::App::start() {

	//run main loop
	//handle events
	for (auto itr = std::begin(*appObjects); itr != std::end(*appObjects); itr++) {
		(*itr)->start();
	}

	glViewport(0, 0, 800, 600);
	Renderer renderer;
	renderer.init();
	while (!window->shouldTerminate()) {
		renderer.render();
		window->swapBuffers();
		eventEmitter->pollEvents();
	}
}

void leo::App::end() {
	//cleanup

	for (auto itr = std::begin(*appObjects); itr != std::end(*appObjects); itr++) {
		(*itr)->end();
	}

	window->terminate();
	delete window;
	delete eventEmitter;
	delete appObjects;
}
