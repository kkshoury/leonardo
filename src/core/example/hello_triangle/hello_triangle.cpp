#include "app.h"


namespace leo_hello_triangle {

	class MyApp : public leo::App, leo::KeyEventListener {
	public:
		virtual void start() override {
			App::start();
		}

		virtual void init() override {
			leo::App::init();
			inputEventEmitter->addKeyListener(this, leo::InputEventEmitter::InputEventType::DOWN);
		}

		virtual void onKeyDown(char key, double t_ms) override {
			std::cout << key << " is Pressed\n";
		}

		virtual void onKeyUp(char key, double t_ms) override {

		}

		virtual void onClick(char key, double t_ms) override {

		}

		virtual void onDoubleClick(char key, double t_ms) override {
		
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

