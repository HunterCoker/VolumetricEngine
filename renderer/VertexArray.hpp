#pragma once

#include "Buffers.hpp"

#include <memory>

class VertexArray {
public:
    VertexArray();
    VertexArray(const VertexArray&) = delete;
    ~VertexArray();

    void bind() const { glBindVertexArray(handle_); }
    void unbind() const { glBindVertexArray(0); }

    void addBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer,
                   const std::shared_ptr<ElementBuffer>& elementBuffer,
                   const BufferLayout& bufferLayout);

    [[nodiscard]] const std::vector<std::shared_ptr<VertexBuffer>>& getVertexBuffers() const { return vertexBuffers_; }
    [[nodiscard]] const std::vector<std::shared_ptr<ElementBuffer>>& getElementBuffers() const { return elementBuffers_; }
private:
    GLuint handle_;
private:
    std::vector<std::shared_ptr<VertexBuffer>> vertexBuffers_;
    std::vector<std::shared_ptr<ElementBuffer>> elementBuffers_;
};
