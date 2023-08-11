#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../renderer/shader.hpp"
#include "../renderer/texture.hpp"
#include "../renderer/camera.hpp"

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/scalar_constants.hpp>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <tiny_gltf.h>

#include <iostream>

int window_width = 1280;
int window_height = 720;

static void glfw_error_callback(int error, const char* description);
static void framebuffer_resize_callback(GLFWwindow* window, int width, int height);

int main() {
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit()) {
		std::cerr << "error: failed to initialize glfw!\n";
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(window_width, window_height, "Volumetric Engine", nullptr, nullptr);
	if (!window) {
		std::cerr << "error: could not create GLFW window!\n";
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);
	glfwSwapInterval(0);

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "error: failed to initialize OpenGL context!\n";
		return -1;
	}
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	// glEnable(GL_CULL_FACE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330 core");


	float vertices[] = {
		 0.5f,  0.5f, 0.0f, 1.0f, 1.0f, // top right
		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
		-0.5f,  0.5f, 0.0f, 0.0f, 1.0f  // top left 
	};

	unsigned int indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	}; 

	float color[3] = { 1.0f, 1.0f, 1.0f };

	camera camera;
	glm::mat4 proj_view = glm::mat4(1.0f);
	glm::mat4 m = glm::mat4(1.0f);
	m = glm::translate(m, glm::vec3(0.0f, 0.0f, -3.0f));

	shader shader("../assets/shaders/vertex.glsl", "../assets/shaders/fragment.glsl");
	shader.bind();

	GLuint vao, vbo, ibo;
	glGenVertexArrays(1 , &vao);
	glBindVertexArray(vao);
	
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, static_cast<void*>(0));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (GLvoid*)(3 * sizeof(float)));

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// tinygltf::Model model;
	// tinygltf::TinyGLTF loader;
	// std::string err;
	// std::string warn;
	// bool ret = loader.LoadBinaryFromFile(&model, &err, &warn, "../assets/models/phoenix_bird.glb");
	// if (!warn.empty())
	// 	printf("Warn: %s\n", warn.c_str());
	// if (!err.empty())
	// 	printf("Err: %s\n", err.c_str());
	// if (!ret) {
	// 	std::cerr << "error: failed to parse GLTF model!\n";
	// 	return -1;
	// }
	
	// std::vector<GLuint> vertex_buffers(model.buffers.size(), 0);
	// glGenBuffers(model.buffers.size(), vertex_buffers.data());
	// for (std::size_t i = 0; i < model.buffers.size(); ++i) {
	// 	auto buffer = model.buffers[i];
	// 	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffers[i]);
	// 	glBufferData(GL_ARRAY_BUFFER, buffer.data.size(), buffer.data.data(), 0);
	// }
	// glBindBuffer(GL_ARRAY_BUFFER, 0);

	// GLuint vertex_array = 0;
	// glGenVertexArrays(1, &vertex_array);
	// glBindVertexArray(vertex_array);

	// glBindBuffer(GL_ARRAY_BUFFER, position_buffer_object);
	// glEnableVertexAttribArray(0);
	// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, position_byte_stride, (void*)position_byte_offset);

	// glBindBuffer(GL_ARRAY_BUFFER, normal_buffer_object);
	// glEnableVertexAttribArray(1);
	// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, normal_byte_stride, (void*)normal_byte_offset);
	
	// glBindBuffer(GL_ARRAY_BUFFER, texcoord_buffer_object);
	// glEnableVertexAttribArray(1);
	// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, texcoord_byte_stride, (void*)texcoord_byte_offset);
	
	float start, end;
	float dt = 0;
	start = static_cast<float>(glfwGetTime());

	while (!glfwWindowShouldClose(window)) {
		end = static_cast<float>(glfwGetTime());
		dt = end - start;
		start = end;

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.05f, 0.05f, 0.09f, 1.0f);
		glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        {
            ImGui::Begin("Debug Window");
			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
            ImGui::ColorPicker3("color", color, 0);
			ImGui::End();
        }

		const static float speed = 1.0f * dt * 2500.0f;

		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
			camera.move(camera::direction::FORWARD, speed);
		}
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
			camera.move(camera::direction::BACKWARD, speed);
		}
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
			camera.move(camera::direction::LEFT, speed);
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
			camera.move(camera::direction::RIGHT, speed);
		}
		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
			camera.move(camera::direction::UP, speed);
		}
		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
			camera.move(camera::direction::DOWN, speed);
		}

		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		camera.track_mouse(xpos, ypos);

		m = glm::rotate(m, dt * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
		proj_view = camera.get_projection_view() * m;
		shader.set_uniform_3f("u_Color", color);
		shader.set_uniform_m4fv("u_ViewProj", proj_view);

		// Rendering
        ImGui::Render();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
	} 

	ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

	return 0;
}

static void glfw_error_callback(int error, const char* description) {
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

void framebuffer_resize_callback(GLFWwindow* window, int width, int height) {
	window_width = width;
	window_height = height;
	glViewport(0, 0, width, height);
}