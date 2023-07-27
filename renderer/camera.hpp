#pragma once

#include <GLFW/glfw3.h>

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

class camera {
public:
	camera(float fovy = 45.0f, float znear = 0.01f, float zfar = 100.0f);
	camera(const camera&) = delete;
	~camera();

	enum class direction {
		FORWARD = 0,
		BACKWARD,
		LEFT,
		RIGHT,
		UP,
		DOWN
	};

	const glm::mat4 get_projection_view() const { return projection_ * view_; }
	void move(direction direction, float speed);
	void track_mouse(double xpos, double ypos);
	
	void update_projection();
	void mouse_callback(GLFWwindow* window, double x, double y);
private:
	glm::mat4 view_, projection_;
	glm::vec3 position_, forward_, up_;
	float fovy_, znear_, zfar_;
	float sensitivity_, yaw_, pitch_;
};