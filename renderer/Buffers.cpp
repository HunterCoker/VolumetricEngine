#include "Buffers.hpp"

VertexBuffer::VertexBuffer()
    :handle_(0) {
    glGenBuffers(1, &handle_);
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &handle_);
}

void VertexBuffer::bufferData(GLsizeiptr size, const void* data) const {
    this->bind();
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void VertexBuffer::bufferSubData(GLintptr offset, GLsizeiptr size, const void* data) {
    this->bind();
    glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
}

ElementBuffer::ElementBuffer()
    :handle_(0), count_(0) {
    glGenBuffers(1, &handle_);
}

ElementBuffer::~ElementBuffer() {
    glDeleteBuffers(1, &handle_);
}

void ElementBuffer::bufferData(GLsizeiptr size, const void *data) {
    this->bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    count_ = size / sizeof(uint32_t);
}
