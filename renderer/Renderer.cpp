#include "Renderer.hpp"

#include <glm/gtc/type_ptr.hpp>

#include <iostream>

Renderer::Renderer()
    :activeScene_(nullptr) {
    quadsShader_ = std::make_unique<Shader>("../assets/shaders/vertex.glsl","../assets/shaders/fragment.glsl");
}

void Renderer::setActiveScene(const std::shared_ptr<Scene>& scene) {
    activeScene_ = scene;

    // QUADS_VAO :: 0
    const auto& quads            = activeScene_->getQuads();
    const auto& quadsVertexArray = vertexArrays_.emplace_back(std::make_unique<VertexArray>());
    quadsVertexArray->bind();

    auto quadsVertexBuffer = std::make_shared<VertexBuffer>();
    auto quadsDataSize = static_cast<GLsizeiptr>(quads.size() * sizeof(Quad));
    auto quadsData = new float[quads.size() * sizeof(Quad) / sizeof(float)];
    for (std::size_t i = 0; i < quads.size(); ++i) {
        auto j = i * sizeof(Quad) / sizeof(float);
        memcpy(&quadsData[j], &quads[i]->botLeft, sizeof(Quad));
    }
    quadsVertexBuffer->bufferData(quadsDataSize, quadsData);

    auto quadsElementBuffer = std::make_shared<ElementBuffer>();
    uint32_t indices[MAX_QUADS * 6];
    uint32_t offset = 0;
    for (std::size_t i = 0; i < MAX_QUADS * 6; i += 6) {
        indices[i + 0] = 0 + offset;
        indices[i + 1] = 1 + offset;
        indices[i + 2] = 2 + offset;
        indices[i + 3] = 2 + offset;
        indices[i + 4] = 3 + offset;
        indices[i + 5] = 0 + offset;
        offset += 4;
    }
    quadsElementBuffer->bufferData(sizeof(indices), indices);

    BufferLayout quadsBufferLayout;
    quadsBufferLayout.pushFloat(3); // position
    quadsBufferLayout.pushFloat(3); // color
    quadsBufferLayout.pushFloat(2); // uv
    quadsBufferLayout.pushFloat(1); // texID

    quadsVertexArray->addBuffer(quadsVertexBuffer, quadsElementBuffer, quadsBufferLayout);
    quadsVertexBuffer->unbind();
    quadsElementBuffer->unbind();

    quadsVertexArray->unbind();
}

void Renderer::render() {
    auto& camera = activeScene_->getCamera();

    quadsShader_->bind();
    quadsShader_->setUniformm4fv("u_ProjView", camera.getProjectionView());

    const auto& quadsVertexArray   = vertexArrays_[QUADS_VAO];
    const auto& quadsElementBuffer = quadsVertexArray->getElementBuffers().front();
    quadsVertexArray->bind();
    quadsElementBuffer->bind();
    glDrawElements(GL_TRIANGLES, quadsElementBuffer->getCount(), GL_UNSIGNED_INT, nullptr);
}