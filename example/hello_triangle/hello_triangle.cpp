#include "../../leo/leonardo.h"

namespace leo_hello_triangle {

	int leo_main(int argc, char* argv) {
		leo::App* app = new leo::App();

		app->preInit();
		app->init();
		app->postInit();
		app->start();
		app->end();

		delete app;

		return 0;
	}

	class MyApp : public leo::App{
		virtual void start() override {
		}
	};
}

