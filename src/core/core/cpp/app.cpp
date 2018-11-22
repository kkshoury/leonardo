#include "app.h"


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
	window->setTitle("Leonardo");
	window->setDim(800, 600);
	window->setOpenGLMajorMinorVersion(4, 3);
	window->init();

	context = new AppFrameworkContext();
	inputEventEmitter = new InputEventEmitter();

	context->renderTarget = window;
	context->inputEventEmitter = inputEventEmitter;

	inputEventEmitter->init(*context);

	for (auto itr = std::begin(*appObjects); itr != std::end(*appObjects); itr++) {
		(*itr)->init(*context);
	}
}

void leo::App::postInit() {
	//set listeners
	//initial setup

	inputEventEmitter->postInit();

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		return;
	}

	for (auto itr = std::begin(*appObjects); itr != std::end(*appObjects); itr++) {
		(*itr)->postInit();
	}
}

void leo::App::start() {

	inputEventEmitter->start();

	//run main loop
	//handle events
	for (auto itr = std::begin(*appObjects); itr != std::end(*appObjects); itr++) {
		(*itr)->start();
	}

	glViewport(0, 0, 800, 600);
	Renderer renderer;
	renderer.init();
	while (!window->shouldTerminate()) {
		inputEventEmitter->pollEvents();
		renderer.render();
		window->swapBuffers();
	}
}

void leo::App::end() {
	//cleanup
	inputEventEmitter->end();
	for (auto itr = std::begin(*appObjects); itr != std::end(*appObjects); itr++) {
		(*itr)->end();
	}

	window->terminate();
}

void leo::App::dispose()
{
	inputEventEmitter->dispose();

	for (auto itr = std::begin(*appObjects); itr != std::end(*appObjects); itr++) {
		(*itr)->dispose();
	}

	delete window;
	delete context;
	delete appObjects;
}
