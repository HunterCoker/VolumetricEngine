#pragma once

#include <glad/glad.h>

#include <vector>

struct BufferLayoutElement {
    GLint count;
    GLenum type;
    GLboolean normalized;

    static uint32_t getSizeOfType(GLenum type) {
        switch (type) {
            case GL_FLOAT:          return 4;
            case GL_UNSIGNED_INT:   return 4;
            default:                return 0;
        }
    }
};

class BufferLayout {
public:
    BufferLayout()
        :stride_(0) {
    }
    BufferLayout(const BufferLayout&) = delete;
    ~BufferLayout() = default;

    [[nodiscard]] GLsizei getStride() const { return stride_; }
    [[nodiscard]] const std::vector<BufferLayoutElement>& getElements() const { return elements_; }

    void pushFloat(int32_t count) {
        elements_.push_back({ count, GL_FLOAT, GL_FALSE });
        stride_ += count * BufferLayoutElement::getSizeOfType(GL_FLOAT);
    }

    void pushUInt(int32_t count) {
        elements_.push_back({ count, GL_UNSIGNED_INT, GL_FALSE });
        stride_ += count * BufferLayoutElement::getSizeOfType(GL_UNSIGNED_INT);
    }
private:
    std::vector<BufferLayoutElement> elements_;
    GLsizei stride_;
};

class VertexBuffer {
public:
    VertexBuffer();
    VertexBuffer(const VertexBuffer&) = delete;
    ~VertexBuffer();

    void bind() const { glBindBuffer(GL_ARRAY_BUFFER, handle_); }
    void unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }

    void bufferData(GLsizeiptr size, const void* data) const;
    void bufferSubData(GLintptr offset, GLsizeiptr size, const void* data);
private:
    GLuint handle_;
};

class ElementBuffer {
public:
    ElementBuffer();
    ElementBuffer(const ElementBuffer&) = delete;
    ~ElementBuffer();

    void bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle_); }
    void unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

    [[nodiscard]] GLsizei getCount() const { return count_; }

    void bufferData(GLsizeiptr size, const void* data);
private:
    GLuint handle_{};
    GLsizei count_;
};

