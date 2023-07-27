#pragma once

#include <glad/glad.h>

#include <string>

class texture {
public:
	texture(const std::string& texture_path);
	texture(const texture&) = delete;
	~texture();

	void bind();
	void unbind();

	void load_from_file(const std::string& texture_path);
private:
	GLuint handle_;
};