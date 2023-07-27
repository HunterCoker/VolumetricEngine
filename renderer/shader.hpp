#pragma once

#include <glad/glad.h>

#include <glm/mat4x4.hpp>

#include <string>

class shader {
public:
	shader(const std::string& vertex_path, const std::string& fragment_path);
	shader(const shader&) = delete;
	~shader();

	void bind();
	void unbind();

	void set_uniform_1f(const std::string& name, float value);
	void set_uniform_3f(const std::string& name, float value[3]);
	void set_uniform_m4fv(const std::string& name, glm::mat4 value);
private:
	GLuint program_;
};