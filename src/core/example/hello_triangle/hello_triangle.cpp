#include "app.h"


namespace leo_hello_triangle {

	class MyApp : public leo::App {
	public:
		virtual void start() override {
			App::start();
		}
	};


	int leo_main(int argc, char* argv) {
		MyApp* app = new MyApp();
		
		app->preInit();
		app->init();
		app->postInit(); 
		app->start();
		app->end();

		delete app;

		return 0;
	}

	
}

