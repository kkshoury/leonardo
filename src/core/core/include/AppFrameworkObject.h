#ifndef _APP_FRAMEWORK_OBJECT_
#define _APP_FRAMEWORK_OBJECT_
#pragma once



namespace leo {

	struct AppFrameworkContext;
	
	class AppFrameworkObject {

	public:
		/*
			preinit():
			AppFrameworkObjects are not not initialized yet in the AppFrameworkContext.
			Call to framework objects will result in errors.
			preInit is used to initialize the required settings and options before
			initializeing this object.
		*/
		virtual void preInit() = 0;

		/*
			init:
			AppFrameworkObjects have been created in the AppFrameworkContext.
			AppFrameworkObjects in the AppFrameworkContext have their required settings
			References to other AppFrameworkObjects can be created
			parameters: 
			context: struct with currently created AppFrameworkContextObjects

		*/
		virtual void init(const AppFrameworkContext& context) = 0;

		/*
			postInit:
			All AppFrameworkObjects have their required framework objects
			Register with observers
		*/
		virtual void postInit() = 0;

		/*
			start:
			Observers are registered. Ready to start
			Implement functionality that is required to execute at the beginning of the 
			framework initialization process


		*/
		virtual void start() = 0;

		/*
			end:
			stop current functionality, stop notifying observers, stop responding to events
			memeory held by object is still allocated and ready to be executed again by start()
		*/
		virtual void end() = 0;

		/*
			dispose:
			all memory is released
		*/
		virtual void dispose() = 0;
	};

}

#endif