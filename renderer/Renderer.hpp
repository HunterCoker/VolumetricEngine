#pragma once

#include "VertexArray.hpp"
#include "Shader.hpp"
#include "../core/Scene.hpp"

#define QUADS_VAO 0

struct RendererSettings {

};

class Renderer {
public:
    Renderer();
    Renderer(const Renderer&) = delete;
    ~Renderer() = default;

    void setActiveScene(const std::shared_ptr<Scene>& scene);
    void render();
private:
    RendererSettings settings_;
    std::shared_ptr<Scene> activeScene_;
private:
    std::unique_ptr<Shader> quadsShader_;
    std::vector<std::unique_ptr<VertexArray>> vertexArrays_;

};