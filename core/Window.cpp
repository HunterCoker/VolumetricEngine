#include "Window.hpp"

#include <iostream>

static void glfw_error_callback(int error, const char* description);
static void framebuffer_resize_callback(GLFWwindow* window, int width, int height);

Window::Window() {
    glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit()) {
		std::cerr << "error: failed to initialize glfw!\n";
		std::exit(-1);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window_ctx_ = glfwCreateWindow(1280, 720, "Sovarian", nullptr, nullptr);
    if (!window_ctx_) {
        std::cerr << "error: could not create GLFW window!\n";
        std::exit(-1);
    }

    glfwMakeContextCurrent(window_ctx_);
    glfwSetFramebufferSizeCallback(window_ctx_, framebuffer_resize_callback);
	glfwSwapInterval(0);
}

Window::~Window() {
	glfwDestroyWindow(window_ctx_);
	glfwTerminate();
}

void Window::update() {
	glfwPollEvents();
	glfwSwapBuffers(window_ctx_);
}

static void glfw_error_callback(int error, const char* description) {
	fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

void framebuffer_resize_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}