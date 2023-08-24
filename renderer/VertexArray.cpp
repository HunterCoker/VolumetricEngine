#include "VertexArray.hpp"

VertexArray::VertexArray()
    :handle_(0) {
    glGenVertexArrays(1, &handle_);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &handle_);
}

void VertexArray::addBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer,
                            const std::shared_ptr<ElementBuffer>& elementBuffer,
                            const BufferLayout& bufferLayout) {
    vertexBuffer->bind();
    uint32_t offset = 0;
    const auto& elements = bufferLayout.getElements();
    for (std::size_t i = 0; i < elements.size(); ++i) {
        const auto& element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized,
                              bufferLayout.getStride(), reinterpret_cast<const void*>(offset));
        offset += element.count * BufferLayoutElement::getSizeOfType(element.type);
    }

    vertexBuffers_.push_back(vertexBuffer);
    elementBuffers_.push_back(elementBuffer);
}