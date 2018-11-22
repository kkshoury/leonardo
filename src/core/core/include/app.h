#pragma once
#include "graphics.h"
#include "components.h"
#include "GLFWEventEmitter.h"
#include "AppFrameworkContext.h"

namespace leo {

	std::vector<std::shared_ptr<leo::AppFrameworkObject>>* getAppObjects();


	class App {

	public:
		virtual void preInit();
		virtual void init();
		virtual void postInit();
		virtual void start();
		virtual void end();
		virtual void dispose();
	private:
		GLRenderTarget* window;
		InputEventEmitter* inputEventEmitter;
		AppFrameworkContext* context;
		std::vector<std::shared_ptr<leo::AppFrameworkObject>>* appObjects;
	};



}


