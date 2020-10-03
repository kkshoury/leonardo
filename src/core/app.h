#pragma once
#include "graphics.h"
#include "components.h"
#include "GLFWEventEmitter.h"
#include "AppFrameworkContext.h"
#include "SceneController.h"

#include<memory>

namespace leo {

	std::unique_ptr<std::vector<leo::AppFrameworkObject*>> getAppObjects();


	class App {

	public:
		virtual void preInit();
		virtual void init();
		virtual void postInit();
		virtual void start();
		virtual void end();
		virtual void dispose();
	private:
		std::unique_ptr<GLFWRenderTarget> window;
		std::unique_ptr < AppFrameworkContext> context;
		std::unique_ptr < std::vector<leo::AppFrameworkObject*> > appObjects;
		std::unique_ptr <SceneController> _ptrSceneController;
	protected:
		std::unique_ptr < InputEventEmitter> inputEventEmitter;
		
	};



}


