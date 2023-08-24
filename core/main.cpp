#include "Application.hpp"

#include <iostream>

int main() {

	auto app = Application::get();
	app->run();
	delete app;

	return 0;
}