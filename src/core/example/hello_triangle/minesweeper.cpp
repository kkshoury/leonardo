#include "app.h"


namespace leo_minesweeper {

	class MinesweeperApp : public leo::App {
	public:
		virtual void start() override {
		
		}
	};

	int leo_main(int argc, char* argv) {
		MinesweeperApp* app = new MinesweeperApp();

		app->preInit();
		app->init();
		app->postInit();
		app->start();
		app->end();

		delete app;

		return 0;
	}


}

