#pragma once

#include "../renderer/Camera.hpp"
#include "../renderer/Primitive.hpp"

#include <string>
#include <memory>
#include <vector>

class Scene {
public:
    Scene() = default;
    Scene(const Scene&) = delete;
    ~Scene();

    static std::shared_ptr<Scene> Load(const std::string& filepath);
    void update(float dt);

    [[nodiscard]] Camera& getCamera() { return camera_; }
    [[nodiscard]] const std::vector<std::unique_ptr<Quad>>& getQuads() const { return quads_; }
private:
    Camera camera_;
    std::vector<std::unique_ptr<Quad>> quads_;
};