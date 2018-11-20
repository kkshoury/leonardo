#pragma once
#include "../graphics/graphics.h"
#include "../components/components.h"
#include "../io/include/GLFWEventEmitter.h"

namespace leo {

	std::vector<std::shared_ptr<leo::AppFrameworkObject>>* getAppObjects();


	class App {

	public:
		virtual void preInit();
		virtual void init();
		virtual void postInit();
		virtual void start();
		virtual void end();
	private:
		GLRenderTarget* window;
		const GLFWEventEmitter* eventEmitter;
		std::vector<std::shared_ptr<leo::AppFrameworkObject>>* appObjects;
	};



}


