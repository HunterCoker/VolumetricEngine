#pragma once

#include <glad/glad.h>

#include <string>

class Texture {
public:
	Texture(const std::string& filepath);
	Texture(const Texture&) = delete;
	~Texture();

	void bind();
	void unbind();
private:
	GLuint handle_;
};