#ifndef _APP_FRAMEWORK_OBJECT_
#define _APP_FRAMEWORK_OBJECT_
#pragma once



namespace leo {

	struct AppFrameworkContext;
	
	class AppFrameworkObject {

	public:
		virtual void preInit() = 0;
		virtual void init(const AppFrameworkContext& context) = 0;
		virtual void postInit() = 0;
		virtual void start() = 0;
		virtual void end() = 0;
		virtual void dispose() = 0;
	};

}

#endif