#include "Application.hpp"

#include <iostream>

Application* Application::instance_s = nullptr;

Application::Application() {

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "error: failed to initialize OpenGL context!\n";
		std::exit(-1);
	}

	// glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	GameLayer* gameLayer = new GameLayer;
	layerStack_.pushLayer(gameLayer);

	GuiLayer* guiLayer = new GuiLayer;
	layerStack_.pushLayer(guiLayer);
}

Application::~Application() {

}

Application* Application::get() {
	if (!instance_s)
        instance_s = new Application;

	return instance_s;
}

void Application::run() {
	float start, end;
	float dt = 0;
	start = static_cast<float>(glfwGetTime());

	auto active_window = window_.getWindow();

	while (!glfwWindowShouldClose(active_window)) {
		end = static_cast<float>(glfwGetTime());
		dt = end - start;
		start = end;
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.05f, 0.05f, 0.09f, 1.0f);

		for (auto layer : layerStack_)
			layer->update(dt);

        window_.update();
	}
}