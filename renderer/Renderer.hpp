#pragma once

#include "VertexArray.hpp"
#include "Shader.hpp"
#include "Texture.hpp"

#include "../scene/Scene.hpp"

#define QUADS_VAO 0

struct RendererSettings {

};

struct RenderData {

};

static RenderData renderData_s;

class Renderer {
public:
    Renderer();
    Renderer(const Renderer&) = delete;
    ~Renderer() = default;

    void init();
    void shutdown();

    void beginScene(const std::shared_ptr<Scene>& scene);
    void endScene();

    /* Primitives */
    void drawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);
    void drawQuad2D(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
    void drawTexturedQuad(const glm::vec3& position, const glm::vec2& size, const std::shared_ptr<Texture>& texture, const glm::vec4& color);
    void drawTexturedQuad2D(const glm::vec2& position, const glm::vec2& size, const std::shared_ptr<Texture>& texture, const glm::vec4& color);

    /* */

    void render();


private:
    RendererSettings settings_;
    std::shared_ptr<Scene> activeScene_;
private:
    std::unique_ptr<Shader> quadsShader_;
    std::vector<std::unique_ptr<VertexArray>> vertexArrays_;

};