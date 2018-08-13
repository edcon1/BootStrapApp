#include "AsteroidsApp.h"

int main() {
	
	// allocation
	auto app = new AsteroidsApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}