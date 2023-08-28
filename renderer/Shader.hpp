#pragma once

#include <glad/glad.h>

#include <glm/mat4x4.hpp>

#include <string>

class Shader {
public:
	Shader(const std::string& vertex_path, const std::string& fragment_path);
	Shader(const Shader&) = delete;
	~Shader();

	void bind();
	void unbind();

	void setUniform1f(const std::string& name, float value);
	void setUniform3f(const std::string& name, float value[3]);
	void setUniformm4fv(const std::string& name, glm::mat4 value);
private:
	GLuint program_;
};