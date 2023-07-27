#include "texture.hpp"

#include <stb_image.h>

texture::texture(const std::string& texture_path) {
	glGenTextures(1, &handle_);
	glBindTexture(GL_TEXTURE_2D, handle_);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	load_from_file(texture_path);

	glBindTexture(GL_TEXTURE_2D, 0);
}

texture::~texture() {
	glDeleteTextures(1, &handle_);
}

void texture::bind() {
	glBindTexture(GL_TEXTURE_2D, handle_);
}

void texture::unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}

void texture::load_from_file(const std::string& texture_path) {
	int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(texture_path.c_str(), &width, &height, &nrChannels, 4);
	glBindTexture(GL_TEXTURE_2D, handle_);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, (void*)data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(data);
}